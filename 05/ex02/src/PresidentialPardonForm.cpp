#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
	: AForm(name, 25, 5)
	, name(name)
{
	std::cout << "PresidentialPardonForm created" << std::endl;
	this->is_signed = false;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
	: AForm(copy)
{
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &assignment)
{
	(void)assignment;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &insert)
{
	return stream << "PresidentialPardonForm \""
				  << insert.name
				  << "\"; Authorization grade: "
				  << insert.grade_auth
				  << ", Execution grade: "
				  << insert.grade_exec
				  << " ("
				  << (insert.is_signed ? "signed" : "unsigned")
				  << ").";
}

std::string	PresidentialPardonForm::getName() const
{
	return this->name;
}

unsigned int	PresidentialPardonForm::getGradeAuth() const
{
	return this->grade_auth;
}

unsigned int	PresidentialPardonForm::getGradeExec() const
{
	return this->grade_exec;
}

void	PresidentialPardonForm::beSigned(Bureaucrat &personnel)
{
	if (this->is_signed)
	{
		std::cout << "Warn: PresidentialPardonForm \""
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
		throw PresidentialPardonForm::GradeTooLowException();
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::ofstream file;
	if (executor.getGrade() <= grade_exec)
	{
		std::cout << name
				  << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw PresidentialPardonForm::GradeTooLowException();
}

std::exception	PresidentialPardonForm::GradeTooHighException()
{
	std::invalid_argument exception( "Exception: PresidentialPardonForm: Grade too high! (possible range 1 - 150)." );
	throw exception;
}

std::exception	PresidentialPardonForm::GradeTooLowException()
{
	std::invalid_argument exception( "Exception: PresidentialPardonForm: Grade too low! (has to be higher than authentication / execution grade)." );
	throw exception;
}