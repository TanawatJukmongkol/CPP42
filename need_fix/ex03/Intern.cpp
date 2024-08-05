#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern	&Intern::operator=(Intern const &assignment)
{
	(void)assignment;
	return *this;
}

static void *makeRobo(std::string name)
{
	return new RobotomyRequestForm(name);
}

static void *makeShrub(std::string name)
{
	return new ShrubberyCreationForm(name);
}

static void *makePres(std::string name)
{
	return new PresidentialPardonForm(name);
}

Form *Intern::makeForm(std::string type, std::string name)
{
	const char *match[] = {
		ROBO_REQ,
		SHRB_REQ,
		PRES_REQ,
		NULL
	};
	void *(*fn[])(std::string) = {
		makeRobo,
		makeShrub,
		makePres
	};
	for (int indx = 0; match[indx]; indx++)
	{
		if (match[indx] == type)
		{
			std::cout << "Intern creates " << (!name.empty()? name : "unnamed") << std::endl;
			return (Form *)fn[indx](!name.empty()? name : "unnamed");
		}
	}
	std::cerr << "Error: makeForm: Invalid form name" << std::endl;
	return NULL;
}
