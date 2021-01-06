#ifndef _ELECTION_H_
#define _ELECTION_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "District.h"
#include "ElectoralMap.h"

/*
struct Candidate{
  int id;
  std::string name;
  Party affiliation;
  std::string party;
  std::map<int, int> votes;

};

class Election{
  public:
  	Election();
  	void selectCandidates();
    void runElection();
    void campaign(Party p, int c);
    void vote();
    void printVotes();
    void printCandidateList();
    void divideVotes();
    void getWinner();
  	std::vector<Candidate> get_Candidates() const {return candidates;}
    std::vector<Candidate> * get_Can() {return &candidates;}
    std::map<Party, int> get_rep_count() {return number_of_reps;}
    friend std::ostream& operator<<(std::ostream& os, const Election& d);

  private:
  	std::vector<Candidate> candidates;
    std::map<Party, int> number_of_reps;

};

class RepresentativeElection : public Election{
public:
    void getWinner();
};
*/


#endif
