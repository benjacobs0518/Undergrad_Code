#ifndef TEXT_UI_H
#define TEXT_UI_H

#include <iostream>
#include <map>
#include <vector>

#include "ElectoralMap.h"

class TextUI {
  public:
    TextUI();
    std::string MainMenu();
    void RouteChoice(ElectoralMap &e, std::string choice);

  private:
    std::vector<std::string> main_menu_;
};


#endif  // TEXT_UI_H
