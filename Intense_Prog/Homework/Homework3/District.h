#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
#include <map>

enum class Party {One, Two, Three, None};

class District {
public:
  	District();

    int get_area() const{return area_;};

    void set_id(int i){id = i;};

    int get_id(){return id;};

    std::map<Party, int> get_constituent() const {return constituents_;}

    std::map<Party, int> * get_constituents_ () {return &constituents_;}

    int get_total_constituents() {return all_constituents;}

    void set_remaining_votes(int r) {remaining_votes = r;}

    int get_remaining_votes() {return remaining_votes;}

    friend std::ostream& operator<<(std::ostream& os, const District& d);

 private:
  std::map<Party, int> constituents_; //all constituents and their designated parties
  int area_; //area of district
  int id; //district id
  int all_constituents; //a total count of the districts constituents
  int remaining_votes; //left over votes from all parties with no candidate

};


#endif
