#include <iostream>
#include <string>
#include <vector>

// Names:
//
//


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".
template <typename T>
std::vector<T> AddToValues2(std::vector<T> a, T b){
  for(int i=0; i < a.size(); i++){
    a[i] = a[i] + b;
  }
  return a;
}

struct demo{
  int num;

  demo operator+(demo i){
    i.num = i.num + num;
    return i;
  }
};


int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> v = {1,2,3,4,5};
    std::vector<int> v1 = AddToValues2(v,2);

    for(int i=0; i < v1.size(); i++){
      std::cout<<v1[i]<<" ";
    }
    std::cout<<std::endl;




    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //There is one version of AddToValues2
    //00000000000001c0 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)


    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> a = {1.2,1.3,1.4};
    std::vector<double> a1 = AddToValues2(a,1.1);

    for(int i=0; i < a1.size(); i++){
      std::cout<<a1[i]<<" ";
    }
    std::cout<<std::endl;

    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //00000000000005a0 T std::__1::vector<double, std::__1::allocator<double> > AddToValues2<double>(std::__1::vector<double, std::__1::allocator<double> >, double)
    //0000000000000380 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of
    // error is produced.
    std::vector<std::string> b = {"cat","dog"};
    std::string s1 = " here";
    b = AddToValues2<std::string>(b,s1);
    //its referencing char variables so you need to cast it as type string


    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.

    std::vector<demo> values = {{10},{20},{30}};
    demo values1 = {50};

    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:
    std::vector<demo> values2 = AddToValues2(values, values1);
    std::cout<< values2[0].num<<std::endl;

    // 14) If there was an error, attempt to fix it.
}
