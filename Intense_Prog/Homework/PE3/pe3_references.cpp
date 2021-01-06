#include <iostream>
#define out

// Name: Ben Jacobs
//

// Write any functions you need here!
void numberNine(int *p9){
  std::cout<<"This is pointer p9 inside the function: "<< *p9<< std::endl;
  *p9 = *p9 + 1;
  std::cout<<"This is pointer p9 inside the function incrimented: "<< *p9<< std::endl;
}

void numberEleven(int &p11){
  std::cout<<"This is reference p11 inside the function: "<< p11<< std::endl;
  p11++;
  std::cout<<"This is reference p11 inside the function incrimented: "<< p11<< std::endl;
}

void numberFourteen(const int a, const int b, out int *sum, out int *diff){
  *sum = a+b;
  *diff = a-b;
}

class Test {
  public:
    Test(){
      val=0;
    };
    Test(int a){
      val=a;
    };
    int getVal(){return val;}

    Test operator+(const Test &t1){
      Test t3;
      t3.val = this->val + t1.val;
      return t3;
    };

    bool operator==(const Test &t1){
      bool t3;
      t3 = (this->val == t1.val);
      return t3;
    };

  private:
    int val;
  };




int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.

    // 1) Declare an int

    std::cout<<std::endl;
    std::cout<<"PROBLEM #1"<<std::endl;
    int h1 = 3;
    std::cout<<"This is integer h1: "<< h1<< std::endl;


    // 2) Declare a pointer to that int
    std::cout<<std::endl;
    std::cout<<"PROBLEM #2"<<std::endl;
    int *p1 = &h1;
    std::cout<<"This is pointer p1: "<< *p1<< std::endl;

    // 3) Increment the int via the pointer
    //dereference -> *p1

    std::cout<<std::endl;
    std::cout<<"PROBLEM #3"<<std::endl;
    std::cout<<"This is p1: "<< *p1<< std::endl;
    *p1 = *p1 + 1;
    std::cout<<"This is integer h1 incremented by 1 through pointer p1: "<< h1<< std::endl;

    // 4) Declare a reference to your int
    std::cout<<std::endl;
    std::cout<<"PROBLEM #4"<<std::endl;
    int &p2 = h1;
    std::cout<<"This is reference p2 to int h1: "<< p2<< std::endl;

    std::cout<<std::endl;
    std::cout<<"PROBLEM #5"<<std::endl;

    // 5) Increment the int via the reference
    p2++;
    std::cout<<"This is reference p2 to int h1 incremented by 1: "<< p2<< std::endl;



    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: Both, the origionalvalue h1 will be changed forcing the value of
    // the pointer p1 to change because of the incriment on reference p2

    h1++;
    std::cout<<std::endl;
    std::cout<<"PROBLEM #6"<<std::endl;
    std::cout<<"H1 was incrimented by h1++"<<std::endl;
    std::cout<<"This is int h1: "<< h1<< std::endl;
    std::cout<<"This is pointer p1: "<< *p1<< std::endl;
    std::cout<<"This is reference p2: "<< p2<< std::endl;


    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: All three varaibles will have been modified, the initial value h1,
    // pointer p1 and reference p2 will all be incremented

    std::cout<<std::endl;
    std::cout<<"PROBLEM #7"<<std::endl;
    *p1 = *p1 + 1;
    std::cout<<"P1 was incrimented by *p1 = *p1 + 1"<<std::endl;
    std::cout<<"This is int h1: "<< h1<< std::endl;
    std::cout<<"This is pointer p1: "<< *p1<< std::endl;
    std::cout<<"This is reference p2: "<< p2<< std::endl;


    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: All three varaibles will have been modified, the initial value h1,
    // pointer p1 and reference p2 will all be incremented

    std::cout<<std::endl;
    std::cout<<"PROBLEM #8"<<std::endl;
    p2++;
    std::cout<<"P2 was incrimented by p2++"<<std::endl;
    std::cout<<"This is int h1: "<< h1<< std::endl;
    std::cout<<"This is pointer p1: "<< *p1<< std::endl;
    std::cout<<"This is reference p2: "<< p2<< std::endl;


    // 9) Write a function that takes an int * parameter. How would you pass the
    // variable from #1 into this function? (write the function header and function call below)
    // You need to pass in a reference as a parameter into the function that requires
    // a pointer argument
    std::cout<<std::endl;
    std::cout<<"PROBLEM #9"<<std::endl;
    numberNine(&h1);
    std::cout<<"This is int h1 outside the function: "<< h1<< std::endl;

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: No, you need to be able to pass in the address or the program will throw errors.


    // 11) Write a function that takes an int & parameter. How would you pass the
    // variable from #1 into this function? (write the function header and call below)
    std::cout<<std::endl;
    std::cout<<"PROBLEM #11"<<std::endl;
    numberEleven(h1);
    std::cout<<"This is int h1 outside the function: "<< h1<< std::endl;

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: No, it throws an error in the system you need to dereference the pointer


    std::cout<<std::endl;
    std::cout<<"PROBLEM #12"<<std::endl;
    numberEleven(*p1);
    std::cout<<"This is int h1 outside the function: "<< h1<< std::endl;


    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: No you can't it will throw an error on the program
    /*
    std::cout<<std::endl;
    std::cout<<"PROBLEM #13"<<std::endl;
    numberEleven(p2);
    std::cout<<"This is int h1 outside the function: "<< h1<< std::endl;
    */

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    int a = 5;
    int b = 20;
    int a1;
    int b1;

    std::cout<<std::endl;
    std::cout<<"PROBLEM #14"<<std::endl;
    std::cout<<"This is int a outside the function: "<< a<< std::endl;
    std::cout<<"This is int b outside the function: "<< b<< std::endl;
    numberFourteen(a,b,&a1,&b1);
    std::cout<<"This is int a outside the function as sum: "<< a1<< std::endl;
    std::cout<<"This is int b outside the function as difference: "<< b1<< std::endl;
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: Return values are good for single arguments and output is better for several

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:
    std::cout<<std::endl;
    std::cout<<"PROBLEM #16"<<std::endl;
    Test k(5);
    Test p(6);
    Test l;
    l = k + p;
    std::cout<<"Value of k:" << k.getVal()<< " Value of p: " << p.getVal() << " Added = "<< l.getVal()<<std::endl;

    if(k == p){
      std::cout<<"K == P"<<std::endl;
    }
    else{
      std::cout<<"K != P"<<std::endl;
    }

}
