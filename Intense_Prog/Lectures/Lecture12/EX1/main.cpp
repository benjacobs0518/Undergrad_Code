#include <iostream>

#include "Animal.h"

// Name(s):

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal
  Reptile charlie("I am a human lizard");
  // 2) Call the Fight method of animal
  ralph.Fight(charlie);
  std::cout << charlie.MakeSound() << std::endl;
  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal

  // 4) Instantiate at least one object of each class you defined for #3
  Mammal bob("I have fur and I am angry");
  std::cout << bob.MakeSound() << std::endl;
  Snake brad("Slippery");
  std::cout << brad.MakeSound() << std::endl;
  // 5) Have a tournament between the animals that you have instantiated
  bob.Fight(brad);
  // 6) turn in Animal.h and main.cpp on canvas

	return 0;
}
