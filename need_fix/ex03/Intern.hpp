#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include <string>

#define ROBO_REQ "robotomy request"
#define SHRB_REQ "shrubbery request"
#define PRES_REQ "presidental request"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &assignment);
		Form *makeForm(std::string type, std::string name);
};

#endif
