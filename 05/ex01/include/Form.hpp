#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Form
{
	public:
		~Form();
		Form(Form const &copy);
		Form &operator=(Form const &assignment);
		Form(const std::string name, const unsigned int grade_auth, const unsigned int grade_exec);
		friend std::ostream &operator<<(std::ostream &stream, const Form &insert);

		std::string		getName() const;
		unsigned int	getGradeAuth() const;
		unsigned int	getGradeExec() const;
		void			beSigned(class Bureaucrat &personnel);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		const unsigned int	grade_auth;
		const unsigned int	grade_exec;
		bool				is_signed;
};

#endif
