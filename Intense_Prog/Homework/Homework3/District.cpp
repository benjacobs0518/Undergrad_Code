#include <iostream>
#include <vector>

#include "District.h"
#include "ElectoralMap.h"

District::District() {
    area_ = (rand()% 25) + 5;
    std::pair<std::string, int> tmp_constitutent;
    for(auto a : ElectoralMap::party_vec){
      constituents_[a] = (rand()%9);
    }

    std::map<Party, int>::iterator it = constituents_.begin();
    while(it != constituents_.end()) {
      all_constituents = all_constituents + it->second;
      it++;
    }

}


std::ostream& operator<<(std::ostream& os, const District& dist){
  std::map<Party, int> constituents = dist.get_constituent();
  std::string sentence = "Square miles: " + std::to_string(dist.get_area());
  os<<sentence<<std::endl;

  int i = 0;
  std::map<Party, int>::iterator it = constituents.begin();
  while(it != constituents.end()) {
    os<<"[Party: " << ElectoralMap::str_party_vec[i] << "] : " << it->second << "        ";
    it++;
    i++;
  }

  return os;

}
