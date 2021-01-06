#include <iostream>

#include "Tree.h"

// Names:
//


int main() {
    Tree oak;
    std::cout << "Number of trees: " << oak.get_number_seeds() << std::endl;

    // 0) Attempt to directly access the number_seeds_ static field here. Can you do so? why/why not?
    // std::cout << oak.number_seeds_ << std::endl;
    // no, its a private field

    // 1) Instantiate another Tree object here
    Tree maple;

    // 2) Call get_number_seeds() from your tree object instantiated at #1
    std::cout << "Number of trees: " << maple.get_number_seeds() << std::endl;

    // 3) Test to see whether pointers to your two Tree objects are equal.
    Tree* pointer = &oak;
    Tree* pointer1 = &maple;

    if(*(pointer) == *(pointer1)){
      std::cout<<"equal"<<std::endl;
    }

    else{
      std::cout<<"NOT equal"<<std::endl;
    }

    // 4) Call Seed() from the Tree object oak and Seed() from the Tree object instantiated at #1
    // Does changing the value of number_seeds_ from one tree object affect what you see from the
    // other Tree object by calling get_number_seeds()?
    oak.Seed();
    std::cout << "Number of seeds oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds maple: " << maple.get_number_seeds() << std::endl;
    maple.Seed();
    std::cout << "Number of seeds oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds maple: " << maple.get_number_seeds() << std::endl;
    //static here changes both values since its inheritance

    // 5) Add a subclass of the Tree object. Your subclass should overwrite the Seed() method so that
    // when your subclass uses Seed(), the number_seeds_ should increase by two. Write adequate code
    // to experiment how the static field changes when calling Seed() with your regular Trees versus with the
    // derived class that you implemented. Don't forget the keyword virtual and remember that you shouldn't
    // add a new field to your Tree subclass to accomplish this!
    Sapling sap;
    std::cout << "Number of seeds from sap: " << sap.get_number_seeds() << std::endl;
    sap.Seed();
    std::cout << "Number of seeds from sap: " << sap.get_number_seeds() << std::endl;

    // 6) Add a public static variable to your Tree class that counts how many Trees (and Tree subclasses)
    // have been instantiated. Can you access this via a Tree instance? Can you access it without an instance of Tree?
    // e.g.
    std::cout << Tree::count << std::endl;
    std::cout << oak.count << std::endl;


}
