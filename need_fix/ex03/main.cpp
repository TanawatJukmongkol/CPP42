#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Form *form = NULL;
	try
	{
		Intern		intern;
		Bureaucrat	bill("Billy the third", 12);
		Bureaucrat	brainrot("Send help", 1);

		form = intern.makeForm(PRES_REQ, "rizz");
		if (form)
		{
			form->beSigned(bill);
			brainrot.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception & e)
	{
		delete form;
		std::cout << "Caught Error: " << e.what() << std::endl;
	}
	return 0;
}
