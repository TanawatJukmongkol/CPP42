#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat				personnel("Jhon", 25);
		Bureaucrat				personnel2("Adam", 5);
		// ShrubberyCreationForm	document("top secret document");
		// RobotomyRequestForm		document("top secret document");
		PresidentialPardonForm		document("top secret document");
		// AForm					abstract_form; // Cannot construct! :D

		personnel.signForm(document);
		personnel2.executeForm(document);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
