#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string name, const int grade_auth, const int grade_exec)
	: name(name)
	, grade_auth(grade_auth)
	, grade_exec(grade_exec)
{
	if (grade_auth > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
	else if (grade_auth < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm created" << std::endl;
	this->is_signed = false;
}

AForm::~AForm()
{
	std::cout << "AForm destroyed" << std::endl;
}

AForm::AForm(AForm const &copy)
	: name(copy.name)
	, grade_auth(copy.grade_auth)
	, grade_exec(copy.grade_exec)
{
	*this = copy;
}

AForm	&AForm::operator=(AForm const &assignment)
{
	(void)assignment;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const AForm &insert)
{
	return stream << "AForm \""
				  << insert.getName()
				  << "\"; Authorization grade: "
				  << insert.getGradeAuth()
				  << ", Execution grade: "
				  << insert.getGradeExec();
}

std::string	AForm::getName() const
{
	return this->name;
}

int	AForm::getGradeAuth() const
{
	return this->grade_auth;
}

int	AForm::getGradeExec() const
{
	return this->grade_exec;
}

void	AForm::beSigned(Bureaucrat &personnel)
{
	if (this->is_signed)
	{
		std::cout << "Warn: AForm \""
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
		throw AForm::GradeTooLowException();
}

void	execute(Bureaucrat const &executor)
{
	(void)executor;
	std::cout << "AForm executed." << std::endl;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Exception: Form: Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Exception: Form: Grade too low!";
}
