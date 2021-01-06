#include <math.h> //Include math functions
#ifndef POINT // this is the header guard
#define POINT //defines the point header
#include <vector>

class Point{ //instatiate Point class
  public:
    Point(int n); //initiates constructor for point default
    Point(std::vector<int> DimensionalCoordinates);//initiates constructor for point vector
    int get_length(){return n;}//returns the length of the vector
    std::vector<int> get_dm(){return DimensionalCoordinates;} //getter of the vector of values for coordinates
    void set_dm(int n, int value){DimensionalCoordinates[n] = value;} //setter for vector values
    void Translate(int off);//initiate the translate function
    float Distance(Point a, Point b);//initiate the distance function


  private:
    std::vector<int> DimensionalCoordinates; //private vector of multi dimensional coordinates
    int n; //length of vector
    /*

    Point(int n); //creates new point function
    Point(int setx, int sety); // creates new point function with coordinate perameters

    int get_x(){return x;} //getter for x
    int get_y(){return y;} // getter for y

    void set_x(int newValX){x=newValX;} //setter for x
    void set_y(int newValY){y=newValY;} // setter for y

    float Distance(Point p); //creates the function distance with point p perameter
    void Translate(int off); // creates the translate function which takes in a positive or negative offset


  private:
      int x; //private int coordinate x
      int y; //private int coordinate y
    */

};

#endif //ends header guard
