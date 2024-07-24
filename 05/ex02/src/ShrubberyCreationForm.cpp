#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: AForm(name, 145, 135)
	, name(name)
{
	std::cout << "ShrubberyCreationForm created" << std::endl;
	this->is_signed = false;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
	: AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &assignment)
{
	(void)assignment;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &insert)
{
	return stream << "ShrubberyCreationForm \""
				  << insert.name
				  << "\"; Authorization grade: "
				  << insert.grade_auth
				  << ", Execution grade: "
				  << insert.grade_exec
				  << " ("
				  << (insert.is_signed ? "signed" : "unsigned")
				  << ").";
}

std::string	ShrubberyCreationForm::getName() const
{
	return this->name;
}

unsigned int	ShrubberyCreationForm::getGradeAuth() const
{
	return this->grade_auth;
}

unsigned int	ShrubberyCreationForm::getGradeExec() const
{
	return this->grade_exec;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &personnel)
{
	if (this->is_signed)
	{
		std::cout << "Warn: ShrubberyCreationForm \""
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
		throw ShrubberyCreationForm::GradeTooLowException();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream file;
	if (executor.getGrade() <= grade_exec)
	{
		std::cout << "ShrubberyCreationForm executed by "
			<< executor.getName()
			<< "! Creating a file..." << std::endl;
		file.open(name + "_shrubbery");
		if (!file.good())
			throw std::runtime_error("Exception: ShrubberyCreationForm: Failed to open file stream.");
		file << "          &&& &&  & &&\n"
			 << "      && &\\/&\\|& ()|/ @, &&\n"
			 << "      &\\/(/&/&||/& /_/)_&/_&\n"
			 << "   &() &\\/&|()|/&\\/ '%\" & ()\n"
			 << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			 << "&&   && & &| &| /& & % ()& /&&\n"
			 << " ()&_---()&\\&\\|&&-&&--%---()~\n"
			 << "     &&     \\|||\n"
			 << "             |||\n"
			 << "             |||\n"
			 << "             |||\n"
			 << "       , -=-~  .-^- _\n"
			 << "              `" << std::endl;
		file.close();
	}
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}

std::exception	ShrubberyCreationForm::GradeTooHighException()
{
	std::invalid_argument exception( "Exception: ShrubberyCreationForm: Grade too high! (possible range 1 - 150)." );
	throw exception;
}

std::exception	ShrubberyCreationForm::GradeTooLowException()
{
	std::invalid_argument exception( "Exception: ShrubberyCreationForm: Grade too low! (has to be higher than authentication / execution grade)." );
	throw exception;
}