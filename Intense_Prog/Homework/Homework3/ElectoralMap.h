#ifndef ELECTORALMAP_H
#define ELECTORALMAP_H

#include "District.h"
#include "Election.h"
#include <map>

struct Candidate{
  int id;
  std::string name;
  Party affiliation;
  std::string party;
  std::map<int, int> votes;

};

class ElectoralMap {
public:

	static ElectoralMap& GetInstance() {
		// gets instantiated the first time
		static ElectoralMap instance; // guaranteed to be destroyed

		return instance;
	}

    std::map<int, District*> get_districts() const {return districtMap;}
    District* get_district(int id);
		ElectoralMap(ElectoralMap const&) = delete; // copy constructor
		void operator=(ElectoralMap const&) = delete; // assignment operator
  	static const int NUM_DISTRICTS;
		static const std::vector<Party> party_vec;
    static const std::vector<std::string> str_party_vec;

friend std::ostream& operator<<(std::ostream& os, const ElectoralMap &map_election);

 private:
 	ElectoralMap();
  std::map<int, District *> districtMap;
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



#endif
