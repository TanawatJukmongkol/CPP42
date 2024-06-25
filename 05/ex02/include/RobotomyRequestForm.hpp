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
		friend std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &insert);

		virtual std::string		getName() const;
		virtual unsigned int	getGradeAuth() const;
		virtual unsigned int	getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name; // target
		const unsigned int	grade_auth = 72;
		const unsigned int	grade_exec = 45;
		bool				is_signed;
};

#endif
