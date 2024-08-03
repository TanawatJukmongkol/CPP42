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

		virtual std::string		getName() const;
		virtual int				getGradeAuth() const;
		virtual int				getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel) = 0;
		virtual void			execute(Bureaucrat const &executor) const = 0;

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
		const std::string		name;
		const int				grade_auth;
		const int				grade_exec;
		bool					is_signed;
};

std::ostream &operator<<(std::ostream &stream, const AForm &insert);

#endif
