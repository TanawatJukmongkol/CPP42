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

		virtual std::string		getName() const;
		virtual int	getGradeAuth() const;
		virtual int	getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name; // target
		const int			grade_auth;
		const int			grade_exec;
		bool				is_signed;
};

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &insert);

#endif
