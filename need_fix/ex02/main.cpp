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
		ShrubberyCreationForm		document1("shrub");
		RobotomyRequestForm			document2("robot");
		PresidentialPardonForm		document3("prez");
		// AForm					abstract_form; // Cannot construct! :D

		personnel1.signForm(document3);
		// document.execute(personnel2);
		personnel2.executeForm(document3);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
