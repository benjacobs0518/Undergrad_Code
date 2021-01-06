#include <iostream>
#include <math.h>
#include <vector>
#include "Point.h"


Point::Point(int a){ //creates constructor for point default
  for(int i=0; i<a; i++) //iterates through a times
  {
    DimensionalCoordinates.push_back(0); //add zero as it is required to be the origin.
  }
  n = a; //set the length of the vector equal to a
}

Point::Point(std::vector<int> a){//creates constructor for point with values
  for(int i = 0; i<a.size(); i++){ //iterates through a times
    DimensionalCoordinates.push_back(a[i]);//add values one by one
  }
  n = a.size(); //set the length of the vector equal to a.size()
}

void Point::Translate(int off){//creates the translate function
  for(int i = 0; i<n; i++){//iterates through all elements in DimensionalCoordinates
    DimensionalCoordinates[i] += off; //changes the values by the offset value
  }
}

float Point::Distance(Point a, Point b){ //distance function takes two point objects
  if(a.n != b.n){ // if the lengths dont math
    std::cout<<"ERROR: length of vectors do not match, please enter two similarly lengthed vectors." << std::endl;
     return 0; //return out
  }
  else{ //if they are the same length
    std::vector<int> v1 = a.get_dm(); //store vector values to local vector
    std::vector<int> v2 = b.get_dm(); //store vector values to local vector

    float total = 0; //create a float value for euclidian dist

    for(int i = 0; i<a.n; i++){ //iterates through entire length
      total += pow((v1[i] - v2[i]),2); //euclidian math
    }

    total = sqrt(total); //square total of all values (x1-x2) etc
    return total; //return final distance
  }

}
