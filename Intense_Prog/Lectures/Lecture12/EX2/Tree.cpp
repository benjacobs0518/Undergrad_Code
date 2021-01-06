#include <vector>

#include "Tree.h"

// no trees to begin with
int Tree::number_seeds_ = 0;

int Tree::count =0;

bool Tree::operator==(Tree &other){
  return number_seeds_ == other.number_seeds_;
}
