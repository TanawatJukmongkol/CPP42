#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &assignment);
		Bureaucrat(const std::string name, int grade);

		std::string		getName() const;
		int				getGrade() const;
		void			promote(int rank);
		void			demote(int rank);
		void			signForm(Form &Form);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	name;
		int 				grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &insert);

#endif
