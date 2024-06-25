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
		//Bureaucrat				personnel("Jhon", 25);
		Bureaucrat					personnel2("Adam", 5);
		// ShrubberyCreationForm	document("top secret document");
		// RobotomyRequestForm		document("top secret document");
		ShrubberyCreationForm		document("top secret document");
		// AForm					abstract_form; // Cannot construct! :D

		personnel2.signForm(document);
		// document.execute(personnel2);
		personnel2.executeForm(document);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
