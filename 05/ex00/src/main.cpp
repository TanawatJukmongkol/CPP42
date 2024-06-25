#include "../include/Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat tony("Tony", 150);
		Bureaucrat john("Jhon", 1);

		std::cout << tony << std::endl;
		tony.promote(1);
		std::cout << john << std::endl;
		john.demote(1);

		/** ERROR!! **/
		// Bureaucrat evil_john("Tony", -1);
		// Bureaucrat evil_tony("Tony", 255);

		// Bureaucrat evil_tim("Tim", 1);
		// evil_tim.promote(1);

		// Bureaucrat evil_linus("Linus", 255);
		// evil_tim.demote(1);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
