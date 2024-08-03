#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &assignment);

		virtual std::string		getName() const;
		virtual int				getGradeAuth() const;
		virtual int				getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

	private:
		const std::string	name; // target
		const int			grade_auth;
		const int			grade_exec;
		bool				is_signed;
};

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &insert);

#endif
