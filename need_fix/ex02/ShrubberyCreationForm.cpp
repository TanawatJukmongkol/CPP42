#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: AForm(name, 145, 135)
	, name(name)
	, grade_auth(145)
	, grade_exec(135)
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
	, name(copy.name)
	, grade_auth(145)
	, grade_exec(135)
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
				  << insert.getName()
				  << "\"; Authorization grade: "
				  << insert.getGradeAuth()
				  << ", Execution grade: "
				  << insert.getGradeExec();
}

std::string	ShrubberyCreationForm::getName() const
{
	return this->name;
}

int	ShrubberyCreationForm::getGradeAuth() const
{
	return this->grade_auth;
}

int	ShrubberyCreationForm::getGradeExec() const
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
	if (!is_signed)
		throw std::runtime_error(
				std::string("ShrubberyCreationForm: ")
				+ name
				+ std::string(" was not signed."));
	if (executor.getGrade() > grade_exec)
		throw ShrubberyCreationForm::GradeTooLowException();
	std::cout << "ShrubberyCreationForm executed by "
		<< executor.getName()
		<< "! Creating a file..." << std::endl;
	file.open((name + "_shrubbery").c_str());
	if (!file.good())
		throw std::runtime_error(
				std::string("ShrubberyCreationForm: ")
				+ name
				+ std::string(" Failed to open file stream."));
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

