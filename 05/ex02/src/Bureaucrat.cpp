#include "../include/Bureaucrat.hpp"
#include <iostream>

/** Orthodox canonical **/

Bureaucrat::Bureaucrat()
{
	std::cout << "Empty bureaucrat created. (useless)" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (name.empty())
	{
		std::cout << "Unnamed Bureaucrat created." << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat \""
				<< name
				<< "\" created" << std::endl;
	}

}

Bureaucrat::~Bureaucrat()
{
	if (name.empty())
	{
		std::cout << "Unnamed Bureaucrat destroyed." << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat \""
				<< name
				<< "\" destroyed" << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}


/** Overloads **/

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &assignment)
{
	(void)(assignment);
	std::cout << "Bureaucrat assigned to bureaucrat \""
			  << assignment.name
			  << "\" (does nothing, because const)." << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &insert)
{
	return stream << insert.getName()
				  << ", bureaucrat grade "
				  << insert.getGrade()
				  << ".";
}

/**	Getter - Setters **/

std::string	Bureaucrat::getName() const
{
	return this->name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::signForm(AForm &AForm)
{
	try {
		AForm.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << name
				  << " couldn't sign "
				  << AForm.getName()
				  << " because "
				  << e.what() << std::endl;
	}
}

void	Bureaucrat::promote(unsigned int rank)
{
	if (this->grade - rank < 1)
		throw GradeTooHighException();
	this->grade -= rank;
	std::cout << "Bureaucrat \""
			  << name
			  << "\" gets promoted to grade "
			  << getGrade()
			  << "!" << std::endl;
}

void	Bureaucrat::demote(unsigned int rank)
{
	if (this->grade + rank > 150)
		throw GradeTooLowException();
	this->grade += rank;
	std::cout << "Bureaucrat \""
			  << name
			  << "\" gets demoted to grade "
			  << grade
			  << "." << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
		std::cout << name
				  << " executed "
				  << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Bureaucrat: " << e.what() << std::endl;
	}
}

/**	Exception **/

std::exception	Bureaucrat::GradeTooHighException()
{
	std::invalid_argument exception( "Exception: Bureaucrat: Grade too high! (possible range 1 - 150)." );
	throw exception;
}

std::exception	Bureaucrat::GradeTooLowException()
{
	std::invalid_argument exception( "Exception: Bureaucrat: Grade too low! (possible range 1 - 150)." );
	throw exception;
}
