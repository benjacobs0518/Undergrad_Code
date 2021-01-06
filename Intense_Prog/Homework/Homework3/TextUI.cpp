#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "TextUI.h"
#include "Election.h"
#include "ElectoralMap.h"

TextUI::TextUI() {
  main_menu_.push_back("direct");
  main_menu_.push_back("representative");
}


std::string TextUI::MainMenu() {
    std::string str_choice;
    bool valid = false;
    while (valid == false) {
      std::cout<<"What kind of election should we have (direct or representative, 0 to stop)?"<<std::endl;
      std::cin >> str_choice;

      if(str_choice == "direct" || str_choice == "representative"){
        valid = true;
      }
      else if(str_choice == "0"){
        valid = true;
      }

    }
    return str_choice;
  }


  void TextUI::RouteChoice(ElectoralMap &e, std::string choice){
    if(choice == "direct"){
      Election election_dir;
      election_dir.printVotes();
      election_dir.getWinner();
      //std::cout<<election_dir<<std::endl;

    }
    else if(choice == "representative"){
      RepresentativeElection election_rep;
      election_rep.getWinner();
  }
}
