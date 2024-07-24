#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Form
{
	public:
		~Form();
		Form(Form const &copy);
		Form &operator=(Form const &assignment);
		Form(const std::string name, const int grade_auth, const int grade_exec);

		std::string		getName() const;
		int				getGradeAuth() const;
		int				getGradeExec() const;
		void			beSigned(class Bureaucrat &personnel);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		const int			grade_auth;
		const int			grade_exec;
		bool				is_signed;
};

std::ostream &operator<<(std::ostream &stream, const Form &insert);

#endif
