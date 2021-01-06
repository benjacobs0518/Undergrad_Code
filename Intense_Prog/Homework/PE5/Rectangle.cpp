/**
Creator: Joshua Rymkiewicz
Worked On: Ben Jacobs

PE5
**/

#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2) {
  if(p1.x > p2.x)
  {
    //swap these
    int temp = p1.x;
    p1.x = p2.x;
    p2.x = temp;
    std::cout << "Negative Points. Unable to create rectangle" << std::endl;
  }
  else if(p1.y > p2.y)
  {
      //swap these
      int temp = p1.y;
      p1.y = p2.y;
      p2.y = temp;
      std::cout << "Negative Points. Unable to create rectangle" << std::endl;
  }
p1_ = p1;
p2_ = p2;
}

int Rectangle::GetWidth() {
  return p2_.x - p1_.x;
}

int Rectangle::GetHeight() {
  return p2_.y - p1_.y;
}

bool Rectangle::Overlaps(Rectangle& other) {
  if (p1_.x > other.p2_.x || other.p1_.x > p2_.x){
      return false;
  }
  if (p1_.y > other.p2_.y || other.p1_.y > p2_.y){
      return false;
  }
  else{
  return true;
  }
}

int Rectangle::CalculateArea() {
  return Rectangle::GetWidth() * Rectangle::GetHeight();
}

void Rectangle::Expand() {
  p1_ = { x: p1_.x - 1, y: p1_.y - 1 };
  p2_ = { x: p2_.x + 1, y: p2_.y + 1 };
}

void Rectangle::Shrink() {
  if((p1_.x + 1 !=  p2_.x - 1) && (p1_.y + 1 != p2_.y - 1)){
    p1_ = { x: p1_.x + 1, y: p1_.y + 1 };
    p2_ = { x: p2_.x - 1, y: p2_.y - 1 };
  }
}

/*
Bugs Found:
Shrink - does not properly modify point1 coordinates
*/
