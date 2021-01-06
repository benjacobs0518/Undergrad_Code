#include "Counter.hpp"
#include <iostream>
#include "string"
#include <map>

using namespace std;
int  main() {
vector<int> i = { 20, 40, 60,80 };
cout<<"STRING:"<<endl;
Counter<string> b;

b.Increment("moose");
b.Increment("bear",3);
cout<<"Testing Increment: "<<endl;
cout<<b<<endl;

b.Decrement("moose");
b.Decrement("bear",3);

cout<<"Testing ostream & Decrement: "<<endl;
cout<<b<<endl;

  return 0;
}
