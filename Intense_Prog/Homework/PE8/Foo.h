#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <map>

class Foo{
public:
  Foo(int bar) : bar_(bar){}
  int CalculateMysteries();
  static int TotalBars();
private:
  int bar_;
  static int baz_;
};

#endif
