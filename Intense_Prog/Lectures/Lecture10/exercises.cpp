#include <iostream>
#include <string>
#include <vector>

// Names:
// Ben Jacobs, Ryan, Ian Meadows, Brian Khang Nguyen
//


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)
std::vector<int> AddToValues(std::vector<int> v1, int v2){
  for(int i=0; i < v1.size(); i++){
    v1[i] += v2;
  }
  return v1;
}

std::vector<double> AddToValues(std::vector<double> v1, double v2){
  for(int i=0; i < v1.size(); i++){
    v1[i] += v2;
  }
  return v1;
}

/*
int Add(int a, int b){
  int c = a+b;
  return c;
}

template <class T>
T Add(T a, T b){
  T c = a + b;
  return T;
}

template <class AddNumber>
AddNumber Add(AddNumber a, AddNumber b){
  AddNumber c = a + b;
  return c;
}
*/
//template <typename T>

// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: Pass by value, Yes they do, they arent pass by ref so they need
// to return type vector in order for the function to yield proper results


int main() {
    // 3) Instantiate an int vector
    std::vector<int> v1 = {1,2,3,4,5};

    // 4) call AddToValues, passing in your int vector and another int.
    std::vector<int> v1Add = AddToValues(v1, 3);
    for(int i=0; i < v1.size(); i++){
      std::cout<<v1Add[i]<<" ";
    }
    std::cout<<std::endl;

    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercises.cpp -c

    // then run the command: nm -C exercises.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //0000000000000100 T AddToValues(std::__1::vector<double, std::__1::allocator<double> >, double)
    //0000000000000000 T AddToValues(std::__1::vector<int, std::__1::allocator<int> >, int)
    // there are two versions of the function, one for type int and one for type double/float
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
