#include <iostream>
#include <map>

#include "ElectoralMap.h"
#include "District.h"

const int ElectoralMap::NUM_DISTRICTS = 4;
const std::vector<std::string> ElectoralMap::str_party_vec = {"One", "Two", "Three", "None"};
const std::vector<Party> ElectoralMap::party_vec = {Party::One, Party::Two, Party::Three, Party::None};

ElectoralMap::ElectoralMap() {
    for(int i = 1; i<NUM_DISTRICTS+1; i++){
      District* pointer = new District();
      pointer->set_id(i);
      districtMap.insert(std::pair<int,District*>(i, pointer));
    }

}

District* ElectoralMap::get_district(int id){
  for(std::map<int, District *>::iterator it = districtMap.begin(); it != districtMap.end(); it++){
    if(it->first == id){
      return it->second;
    }
  }
}


std::ostream& operator<<(std::ostream& os, const ElectoralMap &map_election){
  std::map<int, District*> district = map_election.get_districts();

  for(std::map<int, District *>::iterator it = district.begin(); it != district.end(); it++){
    District *temp = it->second;
    os <<"District "<<it->first<<": "<<std::endl;;
    os << *(temp)<<std::endl;

  }

  return os;

}
