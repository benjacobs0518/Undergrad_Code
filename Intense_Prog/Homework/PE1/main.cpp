#include <iostream>
#include "Point.h"
#include <vector>

/*
void PrintCoord(Point p){ //Prints the basic coordinates of the point to test
    std::cout <<  "x: " << p.get_x() << " y: " << p.get_y() << std::endl;
}

void PrintDist(Point a, Point b){ //prints the distance between two sets of coordinates using the distance function
    std::cout <<  "Distance from " << a.Distance(b) << std::endl;
    std::cout <<  "Distance from " << b.Distance(a) << std::endl;
}
*/

void printPoints(Point a){ //function to print all values in point a
  std::vector<int> v = a.get_dm(); //copy them over locally
  for(int i = 0; i<a.get_length(); i++){ //iterate through all values
    std::cout << v[i] << ' '; // print all indiviual values
  }
  std::cout<<std::endl; //end line
}



int main(){ //main function

std::cout<<"THIS IS A TEST FOR THE FIRST CONSTRUCTOR" << std::endl;
Point test(8); //create point
printPoints(test); //print all point coordinates

std::cout<<"THIS IS A TEST FOR THE SECOND CONSTRUCTOR" << std::endl;
std::vector<int> p1{10,20,30,40};
Point a(p1); //create point
printPoints(a);//print all point coordinates


std::cout<<"THIS IS A TEST FOR THE GET LENGTH FUNCTION" << std::endl;
std::cout<<"The length of vector 'a' is: "<< a.get_length() << std::endl;


std::cout<<"THIS IS A TEST FOR THE SETTER FUNCTION" << std::endl;
printPoints(a);//print all point coordinates
a.set_dm(2,100);//set position 2 to value 100
printPoints(a);//print all point coordinates

std::cout<<"THIS IS A TEST FOR THE GETTER FUNCTION" << std::endl;
std::vector<int> v0 = a.get_dm(); //get a local copy of the vector
std::cout<<"Second entry in a is: "<< v0[1] << std::endl;
printPoints(a);//print all point coordinates

std::cout<<"THIS IS A TEST FOR TRANSLATE FUNCTION +5" << std::endl;
a.Translate(5); //transalte a values by 5
printPoints(a);//print all point coordinates

std::cout<<"THIS IS A TEST FOR TRANSLATE FUNCTION -2" << std::endl;
a.Translate(-2);//transalte a values by -2
printPoints(a);//print all point coordinates

std::cout<<"THIS IS A TEST FOR THE DISTANCE FUNCTION" << std::endl;
std::vector<int> p2{5,10,15,20}; // create vector of ints
Point b(p2); //create point
printPoints(b);//print all point coordinates

float dist = a.Distance(a,b); // run distance method

std::cout<<dist<< " DISTANCE " << std::endl;


}
