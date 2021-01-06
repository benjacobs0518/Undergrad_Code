#ifndef ANIMAL_H
#define ANIMAL_H

// Name(s):
//

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Fight(Animal &opponent);

	virtual int GetPower() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " I have course skin!")
	{}


	int GetPower() { return 3; };

};



// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

class Mammal : public Animal {
public:
	Mammal(std::string sound):
	Animal(sound + " moo!")
	{}

	int GetPower() { return 5; };

};

class Snake : public Reptile {
public:
	Snake(std::string sound):
	Reptile(sound + " ssssss")
	{}

	int GetPower() { return 1; };

};



#endif  // ANIMAL_H
