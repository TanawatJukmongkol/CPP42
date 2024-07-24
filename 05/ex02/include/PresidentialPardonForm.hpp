#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &assignment);
		friend std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &insert);

		virtual std::string		getName() const;
		virtual unsigned int	getGradeAuth() const;
		virtual unsigned int	getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name; // target
		const unsigned int	grade_auth = 25;
		const unsigned int	grade_exec = 5;
		bool				is_signed;
};

#endif
