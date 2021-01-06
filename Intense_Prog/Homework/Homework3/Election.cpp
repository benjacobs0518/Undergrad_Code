#include <iostream>
#include <map>
#include <string>
#include <cmath>

#include "Election.h"
#include "District.h"
#include "ElectoralMap.h"


Election::Election(){
  selectCandidates();
  runElection();
  vote();
  divideVotes();
};

//select candidates continuously asks for the names of the candidates and their respective parties
void Election::selectCandidates(){
  std::string sign_up;
  std::string name;
  int i = 0;
  int tmp_id = 0;

  while(i < ElectoralMap::party_vec.size()-1){
    std::cout<<"Do you want to register a candidate for party " << ElectoralMap::str_party_vec[i]<< " (y or n)? ";
    std::cin>>sign_up;
    if(sign_up == "y"){
      tmp_id++;
      std::cout<<"What is their name? ";
      std::cin>>name;
      Candidate rep;
      Party p = ElectoralMap::party_vec[i];
      rep.name = name;
      rep.affiliation = p;
      rep.party = ElectoralMap::str_party_vec[i];
      rep.id = tmp_id;
      number_of_reps[p] += 1;
      candidates.push_back(rep);
      i=0;
    }
    else{
      i++;
    }
  }

}

//run election facilitates the entire election until the user decides the election is over
void Election::runElection(){
    ElectoralMap &e = ElectoralMap::GetInstance();
    std::cout<<e<<std::endl;
    bool election_active = true;
    bool is_running;
    bool valid_choice;
    int candChoice;
    int distChoice;

    while(election_active == true){
        printCandidateList();
        std::cout<<"Which candidate is campaigning (id) (0 to stop)? ";
        std::cin>>candChoice;

        if(candChoice == 0){
          election_active = false;
        }

        else if(candChoice > 0 && candChoice < candidates.size()+1){
          is_running = true;
          while(is_running == true){
            std::cout<<e<<std::endl;
            distChoice = -1;
            valid_choice = false;

            while(valid_choice == false){
              std::cout<<"Where candidate is this candidate campaigning (id) (0 to stop)? ";
              std::cin>>distChoice;
              if(distChoice < -1 || distChoice < ElectoralMap::NUM_DISTRICTS+1){
                valid_choice = true;
              }
            }

            if(distChoice == 0){
              std::cout<<e<<std::endl;
              is_running = false;
            }
            else if(distChoice > 0 && distChoice< ElectoralMap::NUM_DISTRICTS+1){
              std::cout<<candidates[candChoice-1].name << " is campaigning in district " << distChoice<<std::endl;
              campaign(candidates[candChoice-1].affiliation, distChoice);
            }

          }
        }

    }
}

//capaign is when a candidate chooses to go into a district and calculates constituent swaps
void Election::campaign(Party p, int c){
  float constituent_count = 0;
  float total_constituents = 0;
  float success = 0.0;
  float ex_success = 0.0;
  Party greatest;
  int most;

  ElectoralMap &e = ElectoralMap::GetInstance();
  District *dist = e.get_district(c);
  std::map<Party, int> *temp = dist->get_constituents_();

  int i = 0;
  int index = 0;
  int index_most = 0;

  std::map<Party, int>::iterator it = temp->begin();
  while(it != temp->end()) {
    if(p == it->first){
      constituent_count = it->second + 1;
      constituent_count = constituent_count  * 2;
      index = i;
    }
    else if(it->second > most){
      greatest = it->first;
      most=it->second;
      index_most = i;
    }
    if(i != temp->size()-1){
      total_constituents = total_constituents + it->second;
      i++;
    }
    it++;
  }

  success = (constituent_count/total_constituents);
  success = success * (constituent_count/dist->get_area());
  success = success * 100;

  if(success > 100.0){
    success = 100.0;
  }

  ex_success = success * 0.1;


  std::cout<<"Chances to convert: " << success << "%" <<std::endl;
  std::cout<<"Chances to convert from another party: " << ex_success<<"%"<<std::endl;

  float chance = rand()%100;

  if(chance <= success)
  {
      if(temp->at(Party::None) > 0){
              temp->at(Party::None) -= 1;
              temp->at(p) += 1;
              std::cout<<"Congratulations, you converted someone from None to "<< ElectoralMap::str_party_vec[index] <<std::endl;
      }
      else{
          std::cout<<"Sorry, no one left in Party::None to convert!"<<std::endl;
      }
  }

  if(chance <= ex_success)
  {
      if(temp->at(greatest) > 0){
              temp->at(greatest) -= 1;
              temp->at(p) += 1;
              std::cout<<"Congratulations, you converted someone from " << ElectoralMap::str_party_vec[index_most] << " to "<< ElectoralMap::str_party_vec[index] <<std::endl;
      }
      else{
          std::cout<<"Sorry, no one left to convert!"<<std::endl;
      }
  }

  if(chance > success && chance > ex_success){
      std::cout<<"No one was coverted"<<std::endl;
  }


}

//vote places all the votes from Party::none to the largest party
// it also detects if there is no candidate for that party then to add those consitituents to the remainder votes
void Election::vote(){
  Party greatest;
  int most = 0;
  int index;
  int remainder;

  ElectoralMap &e = ElectoralMap::GetInstance();
  std::map<Party, int> rep_count = get_rep_count();

  for(int i = 1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
    remainder = 0;
    District *dist = e.get_district(i);
    std::cout<<*(dist)<<std::endl;
    std::map<Party, int> *temp = dist->get_constituents_();

    int j = 0;
    std::map<Party, int>::iterator it = temp->begin();
    while(it != temp->end()){
      if(rep_count.find(it->first) != rep_count.end()){
        if(it->second > most){
          greatest = it->first;
          most = it->second;
          index = j;
        }
      }

      if(rep_count.find(it->first) == rep_count.end() && it->first != Party::None){
        remainder = remainder + it->second;
      }
      j++;
      it++;
    }

    while(temp->at(Party::None) > 0){
            temp->at(Party::None) -= 1;
            temp->at(greatest) += 1;
        }

    dist->set_remaining_votes(remainder);

    }
}

//this splits the amount of votes up per party and randomly assings constituents to a candidate
void Election::divideVotes(){

  ElectoralMap &e = ElectoralMap::GetInstance();
  std::vector<Candidate> *cand = get_Can();
  std::map<Party, int> rep_count = get_rep_count();
  std::pair<Party, int> largest;

  std::map<Party, int>::iterator it = rep_count.begin(); //go through list of parties and quantities
  while(it != rep_count.end()){
    if(largest.second < it->second){
      largest.first = it->first;
      largest.second = it->second;
    }
    it++;
  }

  for(int i = 1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
    District *dist = e.get_district(i);
    std::map<Party, int> *temp = dist->get_constituents_();
    int total = dist->get_total_constituents();

    std::map<Party, int>::iterator it = rep_count.begin(); //go through list of parties and quantities
    while(it != rep_count.end()){

      std::vector<int> split_votes;
      int numVotes;
      int reps = it->second;

      std::map<Party, int>::iterator itt = temp->begin();
      while(itt != temp->end()){
        if(it->first == itt->first){
          numVotes = itt->second;
        }
        itt++;
      }

      if(it->first == largest.first){
        numVotes = numVotes + dist->get_remaining_votes();
      }

        for(int j = 0; j < reps; j++){
          if(j+1 == reps){
            split_votes.push_back(numVotes);
            total = total - numVotes;
          }
          if(j+1 != reps){
            int temp = rand()%numVotes;
            numVotes = numVotes - temp;
            split_votes.push_back(temp);
            total = total - temp;
          }
        }


        int t = 0;
        std::vector<Candidate>::iterator c = cand->begin();
        while(c != cand->end()) {
          if(c->affiliation == it->first){
            c->votes[i] = split_votes[t];
            t++;
          }
          c++;
        }

        it++;
      }
    }
    std::cout<<std::endl;
}

//counts the amount of consitutents each candidate recieved and prints the winner
void Election::getWinner(){
  std::string winner;
  int largest_count = -1;

  int temp_count;

  std::vector<Candidate> *cand = get_Can();
  std::vector<Candidate>::iterator c = cand->begin();

  std::cout<<std::endl;
  std::cout<<"Full results:"<<std::endl;

  while(c != cand->end()){
    temp_count = 0;

    for(int i=1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
      temp_count = temp_count + c->votes[i];
    }

    if(temp_count > largest_count){
      largest_count = temp_count;
      winner = c->name;
    }

    std::cout<<c->name << ": " << temp_count << std::endl;
    c++;
  }

  std::cout<<std::endl;
  std::cout<<"Congratulations, " << winner << " you've won!"<<std::endl;
}

//print all the votes for each candidate and each district
void Election::printVotes(){
  std::vector<Candidate> *cand = get_Can();
  std::vector<Candidate>::iterator c = cand->begin();
  while(c != cand->end()) {
    std::cout<<std::endl;
    std::cout<< "Candidate :" << c->name << std::endl;
    std::map<int,int>::iterator district_vote_count = c->votes.begin();
    while(district_vote_count != c->votes.end()){
      std::cout<<"District : "<< district_vote_count->first << " Total votes: " << district_vote_count->second<<std::endl;
      district_vote_count++;
    }
    c++;
  }
}

//prints a list of all the candidates for display on run election
void Election::printCandidateList(){
  std::cout<<"---------------"<<std::endl;
  std::vector<Candidate>::iterator it = candidates.begin();
  while(it != candidates.end()) {
    std::cout << it->id << ": " << it->name << " [Party: "<< it->party <<"]"<<std::endl;
    it++;
  }
}

//allows to print object
std::ostream& operator<<(std::ostream& os, const Election& elec){
  std::vector<Candidate> candidates = elec.get_Candidates();

  os<<"---------------"<<std::endl;
  std::vector<Candidate>::iterator it = candidates.begin();
  while(it != candidates.end()) {
    os<< it->id << ": " << it->name << " [Party: "<< it->party <<"]"<<std::endl;
    it++;
  }

  return os;
}

//counts the amount of consitutents each candidate recieved, calculates how many votes a candidate can get
// tallies up all the votes by candidate and declaires the winner for representative election
void RepresentativeElection::getWinner(){

  std::string winner;


  ElectoralMap &e = ElectoralMap::GetInstance();
  std::vector<Candidate> *cand = get_Can();
  std::map<int,int> votes_allowed;
  std::map<std::string, int> results;
  float all_districts_constit = 0;

  std::cout<<std::endl;
  std::cout<<"Full results:"<<std::endl;

  for(int i=1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
    District *dist = e.get_district(i);
    all_districts_constit = all_districts_constit + dist->get_total_constituents();
  }


  float temp;
  for(int i=1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
    District *dist = e.get_district(i);
    temp = dist->get_total_constituents()/all_districts_constit;
    temp = temp * (5*ElectoralMap::NUM_DISTRICTS);
    temp = floor(temp);
    votes_allowed[i] = floor(temp);
  }



  int largest;
  std::string dist_winner;
  for(int i=1; i < ElectoralMap::NUM_DISTRICTS+1; i++){
      largest = -1;

      std::vector<Candidate>::iterator c = cand->begin();
      while(c != cand->end()){
          if(c->votes[i] > largest){
            dist_winner = c->name;
            largest = c->votes[i];
          }
          c++;
        }

      results[dist_winner] += votes_allowed[i];
      std::cout<< "District: " << i << std::endl;
      std::cout<< dist_winner << ": " << votes_allowed[i] <<std::endl;

    }

  largest = 0;
  std::map<std::string, int>::iterator w = results.begin();
  while(w != results.end()){
    if(w->second > largest){
      winner = w->first;
      largest = w->second;
    }
    w++;
  }

  std::cout<<std::endl;
  std::cout<<"Congratulations, " << winner << " you've won!"<<std::endl;


}
