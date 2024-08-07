#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, 72, 45)
	, name(name)
	, grade_auth(72)
	, grade_exec(45)
{
	std::cout << "RobotomyRequestForm created" << std::endl;
	this->is_signed = false;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
	: AForm(copy)
	, name(copy.name)
	, grade_auth(72)
	, grade_exec(45)
{
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &assignment)
{
	(void)assignment;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &insert)
{
	return stream << "RobotomyRequestForm \""
				  << insert.getName()
				  << "\"; Authorization grade: "
				  << insert.getGradeAuth()
				  << ", Execution grade: "
				  << insert.getGradeExec();
}

std::string	RobotomyRequestForm::getName() const
{
	return this->name;
}

int	RobotomyRequestForm::getGradeAuth() const
{
	return this->grade_auth;
}

int	RobotomyRequestForm::getGradeExec() const
{
	return this->grade_exec;
}

void	RobotomyRequestForm::beSigned(Bureaucrat &personnel)
{
	if (this->is_signed)
	{
		std::cout << "Warn: RobotomyRequestForm \""
				  << this->name
				  << "\" is already signed." << std::endl;
		return ;
	}
	if (personnel.getGrade() <= grade_auth)
	{
		is_signed = true;
		std::cout << personnel.getName()
				  << " signed "
				  << name << std::endl;
	}
	else
		throw RobotomyRequestForm::GradeTooLowException();
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(0));
	if (!is_signed)
		throw std::runtime_error(
				std::string("RobotomyRequestForm: ")
				+ name
				+ std::string(" was not signed."));
	if (executor.getGrade() > grade_exec)
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "RobotomyRequestForm executed by "
		<< executor.getName()
		<< "! Bzzzzzz!!!!!" << std::endl;
	if (rand() % 10 < 5)
		std::cerr << "Target "
				  << name
				  << " failed to robotomize." << std::endl;
	else
		std::cout << "Target "
				  << name
				  << " has been robotomized successfully." << std::endl;
}

