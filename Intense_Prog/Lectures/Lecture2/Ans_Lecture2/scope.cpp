#include <iostream>
#include <vector>

// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?

// 2) what happens if we make everything global?


// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
// Josh R.

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void IntTest(int x){
  x++;
  std::cout<<"During IntTest: " << x <<std::endl;
}

// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void StrTest(std::string x){
  x += "Donkey";
  std::cout<<"During StrTest: " << x <<std::endl;
}


// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:
void ArrayTest(int x[], int size){

  std::cout<<"During ArrayTest: ";
  for(int i=0; i < size; i++)
  {
    x[i] = x[i] * x[i];
    std::cout<<x[i]<< " ";
  }
  std::cout<<std::endl;
}

// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer:
void VecTest(std::vector<int> nums){
  nums.push_back(40);
  std::cout<<"During VecTest: ";
  for (int x : nums)
      std::cout << x << " ";

  std::cout<<std::endl;
}


int main() {
  //Question 1
    int y = 10;
    std::cout<<"Before: "<< y<<std::endl;
    IntTest(y);
    std::cout<<"After:  "<<y<<std::endl;

std::cout<<std::endl;

//Question 2
    std::string z = "Cheese";
    std::cout<<"Before: "<< z<<std::endl;
    StrTest(z);
    std::cout<<"After:  "<<z<<std::endl;

std::cout<<std::endl;

//Question 3
    int a[] = {1,2,3,4,5};
    int length = sizeof(a)/sizeof(a[0]);
    std::cout<<"Before: ";
    for(int i=0; i < length; i++)
    {
      std::cout<<a[i]<< " ";
    }
    std::cout<<std::endl;
    ArrayTest(a, length);
    std::cout<<"After:  ";
    for(int i=0; i <length; i++)
    {
      std::cout<<a[i]<< " ";
    }
    std::cout<<std::endl;

std::cout<<std::endl;

//Question 4
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    std::cout<<"Before: ";
    for (int x : nums)
        std::cout << x << " ";

    std::cout<<std::endl;

    VecTest(nums);

    std::cout<<"After: ";
    for (int x : nums)
        std::cout << x << " ";

    std::cout<<std::endl;




    // code to call your functions goes here.

    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or
    // pass-by-reference

}
