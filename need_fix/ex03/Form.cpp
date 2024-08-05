#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string name, const int grade_auth, const int grade_exec)
	: name(name)
	, grade_auth(grade_auth)
	, grade_exec(grade_exec)
{
	if (grade_auth > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	else if (grade_auth < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form created" << std::endl;
	this->is_signed = false;
}

Form::~Form()
{
	std::cout << "Form destroyed" << std::endl;
}

Form::Form(Form const &copy)
	: name(copy.name)
	, grade_auth(copy.grade_auth)
	, grade_exec(copy.grade_exec)
{
	*this = copy;
}

Form	&Form::operator=(Form const &assignment)
{
	(void)assignment;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Form &insert)
{
	return stream << "Form \""
				  << insert.getName()
				  << "\"; Authorization grade: "
				  << insert.getGradeAuth()
				  << ", Execution grade: "
				  << insert.getGradeExec();
}

std::string	Form::getName() const
{
	return this->name;
}

int	Form::getGradeAuth() const
{
	return this->grade_auth;
}

int	Form::getGradeExec() const
{
	return this->grade_exec;
}

void	Form::beSigned(Bureaucrat &personnel)
{
	if (this->is_signed)
	{
		std::cout << "Warn: Form \""
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
		throw Form::GradeTooLowException();
}

void	execute(Bureaucrat const &executor)
{
	(void)executor;
	std::cout << "Form executed." << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Exception: Form: Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Exception: Form: Grade too low!";
}
