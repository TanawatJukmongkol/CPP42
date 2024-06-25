#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <time.h> 

Base	*generate(void)
{
	srand(time(0)); 
	switch (rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	// It identifies class that will not throw NULL.
	std::cout << "Class name: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unidentified." << std::endl;
}

void	identify(Base& p)
{
	// Like the first, but with "bad_cast" exception.
	std::cout << "Class name: ";
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; }
	catch (std::exception e) {
		try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; }
		catch (std::exception e) {
			try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; }
			catch (std::exception e) { 	std::cout << "unidentified." << std::endl; }
		}
	}
}

int main()
{
	Base	*rand_class = generate();
	A		exact_class_A;
	B		exact_class_B;
	C		exact_class_C;

	(void)rand_class;
	std::cout << "# Random class" << std::endl;
	identify(rand_class);
	std::cout << "# Referenced class" << std::endl;
	identify(exact_class_A);
	identify(exact_class_B);
	identify(exact_class_C);

	delete rand_class; // Don't forget lol
	return 0;
}
