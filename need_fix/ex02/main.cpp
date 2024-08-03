#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat					personnel1("Jhon", 25);
		Bureaucrat					personnel2("Adam", 5);
		Bureaucrat					personnel3("Adam", 120);
		ShrubberyCreationForm		document1("shrub");
		RobotomyRequestForm			document2("robot");
		PresidentialPardonForm		document3("prez");
		// AForm					abstract_form; // Cannot construct! :D

		personnel1.signForm(document3);
		personnel2.executeForm(document3);
		
		// Error
		// personnel1.signForm(document2);
		// document2.execute(personnel3);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
