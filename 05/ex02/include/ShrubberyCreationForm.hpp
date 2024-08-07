#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &assignment);
		friend std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &insert);

		virtual std::string		getName() const;
		virtual unsigned int	getGradeAuth() const;
		virtual unsigned int	getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name; // target
		const unsigned int	grade_auth = 145;
		const unsigned int	grade_exec = 135;
		bool				is_signed;
};

#endif
