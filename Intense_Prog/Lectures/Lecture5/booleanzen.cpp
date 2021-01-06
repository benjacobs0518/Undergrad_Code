#include <iostream>
#include <vector>


bool IsEven(const int num) {
    if (num % 2 == 0) {
        return true;
      }
        return false;
}

int AbsoluteValue(int num) {
  /*
    if (num > 0){}
    else {
        num *= -1;
    }
    */
    return num*=-1;
}

int main() {
    std::cout << IsEven(7) << std::endl;
    std::cout << IsEven(2) << std::endl;
    std::cout << IsEven(-16) << std::endl;

    std::cout << std::endl;


    std::cout << AbsoluteValue(7) << std::endl;
    std::cout << AbsoluteValue(2) << std::endl;
    std::cout << AbsoluteValue(-16) << std::endl;
}
