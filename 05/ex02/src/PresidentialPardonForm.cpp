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
				  << insert.getName()
				  << "\"; Authorization grade: "
				  << insert.getGradeAuth()
				  << ", Execution grade: "
				  << insert.getGradeExec();
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
		return ;
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

	if (!is_signed)
		throw std::runtime_error(
				std::string("PresidentialForm: ")
				+ name
				+ std::string(" was not signed."));
	if (executor.getGrade() > grade_exec)
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << name
			  << " has been pardoned by Zaphod Beeblebrox" << std::endl;
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
