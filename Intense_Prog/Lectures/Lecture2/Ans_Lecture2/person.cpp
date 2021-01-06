#include <iostream>

// primarily about structure for data
struct Person {
    std::string name;
    int age;
};

// data + functionality
class Family {
    public:
        Family(int num) {
            num_ = num;
        }

        void Grow(int num_persons) {num_ += num_persons;}; // method

    private:
        // fields/attributes
        int num_;
};

int main() {
    Person p;
    p.name = "Alice";
    p.age = 12;
    std::cout<<p<< std::endl;

    Person q;
    q.name = "Alice";
    q.age = 12;
    std::cout<<q<< std::endl;

    if(p==q){
      std::cout<<"Structs are equal" << std::endl;
    }
    else{
      std::cout<<"Structs are NOT equal" << std::endl;
    }

    Family f1(4);
    f1.Grow(4);


    Family * f2 = new Family(10);
    f2->Grow(8);


    // Exercises: find out if two different structs containing the same data are ==
    // What happens if you try to << a struct to cout? why?
    // It would throw an error due to binary conversion. Not
}
