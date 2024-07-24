#ifndef AForm_HPP
# define AForm_HPP

#include <string>

class AForm
{
	public:
		virtual ~AForm();
		AForm(AForm const &copy);
		AForm &operator=(AForm const &assignment);
		AForm(const std::string name, const int grade_auth, const int grade_exec);
		friend std::ostream &operator<<(std::ostream &stream, const AForm &insert);

		virtual std::string		getName() const = 0;
		virtual unsigned int	getGradeAuth() const = 0;
		virtual unsigned int	getGradeExec() const = 0;
		virtual void			beSigned(class Bureaucrat &personnel) = 0;
		virtual void			execute(Bureaucrat const &executor) const = 0;

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		const unsigned int	grade_auth;
		const unsigned int	grade_exec;
		bool				is_signed;
};

#endif
