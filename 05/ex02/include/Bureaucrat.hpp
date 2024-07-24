#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &assignment);
		Bureaucrat(const std::string name, int grade);
		friend std::ostream &operator<<(std::ostream &stream, const Bureaucrat &insert);

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			signForm(AForm &AForm);
		void			promote(unsigned int rank);
		void			demote(unsigned int rank);
		void			executeForm(AForm const &form);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		unsigned int 		grade;
};

#endif
