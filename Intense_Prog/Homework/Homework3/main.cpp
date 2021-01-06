#include <iostream>
#include <fstream>

#include "ElectoralMap.h"
#include "District.h"
#include "Election.h"
#include "TextUI.h"

int main() {

  ElectoralMap &e = ElectoralMap::GetInstance();
  
  TextUI ui;
  std::string choice;
  while (choice != "0") {
    choice = ui.MainMenu();
    ui.RouteChoice(e, choice);
    std::cout << std::endl;
  }

}
