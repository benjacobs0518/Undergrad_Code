#include <iostream>
#include <math.h>
#include <vector>
#include "Player.h"

Player::Player(const std::string name, const bool is_human){
  name_ = name;
  is_human_=is_human;
  pos_.row = 0;
  pos_.col = 0;
}

void Player::ChangePoints(const int x){
  points_ += x;
}

void Player::SetPosition(Position pos){
  pos_.row = pos.row;
  pos_.col = pos.col;
}

std::string Player::ToRelativePosition(Position other){
  int ydiff = pos_.row - other.row;
  int xdiff = pos_.col - other.col;
  if(ydiff==1){
    return "Up";
  }
  else if(ydiff==-1){
    return "Down";
  }
  else if(xdiff==1){
    return "Left";
  }
  else if(xdiff==-1){
    return "Right";
  }
  else{
    return "Not valid";
  }

}
