#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, 72, 45)
	, name(name)
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
				  << insert.name
				  << "\"; Authorization grade: "
				  << insert.grade_auth
				  << ", Execution grade: "
				  << insert.grade_exec
				  << " ("
				  << (insert.is_signed ? "signed" : "unsigned")
				  << ").";
}

std::string	RobotomyRequestForm::getName() const
{
	return this->name;
}

unsigned int	RobotomyRequestForm::getGradeAuth() const
{
	return this->grade_auth;
}

unsigned int	RobotomyRequestForm::getGradeExec() const
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
	if (executor.getGrade() <= grade_exec)
	{
		std::cout << "RobotomyRequestForm executed by "
			<< executor.getName()
			<< "! Bzzzzzz!!!!!" << std::endl;
		if (rand() % 10 < 5)
		{
			std::cerr << "Target "
					  << name
					  << " failed to robotomize." << std::endl;
		}
		else {
			std::cout << "Target "
					  << name
					  << " has been robotomized successfully." << std::endl;
		}
	}
	else
		throw RobotomyRequestForm::GradeTooLowException();
}

std::exception	RobotomyRequestForm::GradeTooHighException()
{
	std::invalid_argument exception( "Exception: RobotomyRequestForm: Grade too high! (possible range 1 - 150)." );
	throw exception;
}

std::exception	RobotomyRequestForm::GradeTooLowException()
{
	std::invalid_argument exception( "Exception: RobotomyRequestForm: Grade too low! (has to be higher than authentication / execution grade)." );
	throw exception;
}