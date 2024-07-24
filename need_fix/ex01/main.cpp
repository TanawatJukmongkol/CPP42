#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat	personnel("Jhon", 6);
		Form		document("top secret document", 5, 10);

		personnel.promote(1);
		std::cout << document << std::endl;
		personnel.signForm(document);
		std::cout << document << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
