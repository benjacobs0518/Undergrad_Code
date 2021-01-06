#include <iostream>
#include "Earth.h"

// Names:
//

int main(int argc, char **argv){
	/*
		Earth e;
		Earth e1 = e;
		Earth e2(e);
*/

    // 0) Implement your Earth's constructor in Earth.cpp
		Earth &e = Earth::GetInstance();
    // 1) Get an instance of your earth object
		Earth &e1 = Earth::GetInstance();
    // 2) Get another instance of your earth object

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
		if(&e == &e1){
			std::cout<<"The memory addresses match"<<std::endl;
		}
		else{
			std::cout<<"Don't match"<<std::endl;
		}

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?

		e.IncreasePopulation();
		std::cout<<"Origional pop: "<< e.get_population() << std::endl;
		std::cout<<"Origional pop: "<< e1.get_population() << std::endl;

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?

		Earth e5 = e;
		std::cout<<"Origional population "<<e.get_population()<<std::endl;
		std::cout<<"e5 population "<<e5.get_population()<<std::endl;
		e.IncreasePopulation();
		std::cout<<"Origional population "<<e.get_population()<<std::endl;
		std::cout<<"e5 population "<<e5.get_population()<<std::endl;

		Earth e6(e);
		std::cout<<"Origional population "<<e.get_population()<<std::endl;
		std::cout<<"e6 population "<<e6.get_population()<<std::endl;
		e.IncreasePopulation();
		std::cout<<"Origional population "<<e.get_population()<<std::endl;
		std::cout<<"e6 population "<<e6.get_population()<<std::endl;



	return 0;
}
