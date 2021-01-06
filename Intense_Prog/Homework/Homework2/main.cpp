#include "Counter.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int main() {

//COUNTER NO PARAM
  Counter<string> a;
  Counter<int> a1;
  a.printMap();

//COUNTER PARAM
  vector<int> t1 = {10,20,20,30,30,50,70,70,70};
  vector<string> t2 = {"aa","aa","aa","bb","bb","cc","cc","dd","dd","dd","ee"};
  Counter<int> b(t1);
  Counter<string> b1(t2);
  b.printMap();
  std::cout<<std::endl;
  b1.printMap();

//COUNT NO PARAM
std::cout<<"int test for count no param: "<<b.Count() <<std::endl;
std::cout<<"string test for count no param: "<<b1.Count() <<std::endl;

//COUNT WITH KEY param
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for count with key 20: "<<b.Count(20) <<std::endl;
std::cout<<"string test for count with key cc: "<<b1.Count("cc") <<std::endl;

//COUNT WITH MIN MAX param
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for count min 9 max 31 max: "<<b.Count(9,31) <<std::endl;
std::cout<<"string test for count min aa max cc: "<<b1.Count("aa","cc") <<std::endl;

//Remove key
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for remove key 50"<<std::endl;
b.Remove(50);
b.printMap();
std::cout<<"string test for remove key ee"<<std::endl;
b1.Remove("ee");
b1.printMap();

//void Increment
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for incriment key 40"<<std::endl;
b.Increment(30);
b.printMap();
std::cout<<"string test for incriment key dd"<<std::endl;
b1.Increment("dd");
b1.printMap();

//void Increment with quantity n
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for incriment key 40 by 4"<<std::endl;
b.Increment(40,5);
b.printMap();
std::cout<<"string test for incriment key cc by 2"<<std::endl;
b1.Increment("cc",2);
b1.printMap();

//void Decrement
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for Decrement key 40"<<std::endl;
b.Decrement(40);
b.printMap();
std::cout<<"string test for Decrement key cc"<<std::endl;
b1.Decrement("cc");
b1.printMap();

//void Decrement with quantity n
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for Decrement key 70 by 3"<<std::endl;
b.Decrement(70,3);
b.printMap();
std::cout<<"string test for Decrement key aa by 2"<<std::endl;
b1.Decrement("aa",2);
b1.printMap();

// MostCommon
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for MostCommon: "<<b.MostCommon()<<std::endl;
b.printMap();
std::cout<<"string test for MostCommon: "<<b1.MostCommon()<<std::endl;
b1.printMap();

// MostCommon with Param n
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for MostCommon top 6: "<<std::endl;
std::vector<int> most_comm_int = b.MostCommon(6);
for(int i = 0; i < most_comm_int.size(); i++){
  std::cout<<most_comm_int[i]<<std::endl;
}

std::cout<<"string test for MostCommon top 3: "<<std::endl;
std::vector<string> most_comm_string = b1.MostCommon(3);
for(int i = 0; i < most_comm_string.size(); i++){
  std::cout<<most_comm_string[i]<<std::endl;
}

// Leastcommon
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for LeastCommon: "<<b.LeastCommon()<<std::endl;
b.printMap();
std::cout<<"string test for LeastCommon: "<<b1.LeastCommon()<<std::endl;
b1.printMap();

// Leastcommon with Param n
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for LeastCommon top 2: "<<std::endl;
std::vector<int> least_comm_int = b.LeastCommon(2);
for(int i = 0; i < least_comm_int.size(); i++){
  std::cout<<least_comm_int[i]<<std::endl;
}

std::cout<<"string test for LeastCommon top 5: "<<std::endl;
std::vector<string> least_comm_string = b1.LeastCommon(5);
for(int i = 0; i < least_comm_string.size(); i++){
  std::cout<<least_comm_string[i]<<std::endl;
}

// Normalized
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for Normalized: "<<std::endl;
std::map<int,double> int_normalized = b.Normalized();
for (std::pair<int, double> pair : int_normalized) {
std::cout << pair.first << " : " << pair.second << std::endl;
}

std::cout<<"string test for Normalized: "<<std::endl;
std::map<std::__1::basic_string<char>,double> string_normalized = b1.Normalized();
for (std::pair<std::__1::basic_string<char>, double> pair : string_normalized) {
std::cout << pair.first << " : " << pair.second << std::endl;
}

// Keys
std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"int test for Keys: "<<std::endl;
std::set<int> int_keys = b.Keys();
std::set<int>::iterator it;
for (it=int_keys.begin(); it!=int_keys.end(); it++){
  std::cout<< *it << std::endl;
}

std::cout<<"string test for Keys: "<<std::endl;
std::set<std::__1::basic_string<char>> string_keys = b1.Keys();
std::set<std::__1::basic_string<char>>::iterator itt;
for (itt=string_keys.begin(); itt!=string_keys.end(); itt++){
  std::cout<< *itt << std::endl;
}

std::cout<<"--------------------------------------------------------"<<std::endl;
std::cout<<"OVERRIDE"<<std::endl;
std::cout<<b<<std::endl;
std::cout<<b1<<std::endl;



}
