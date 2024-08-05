#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &assignment);

		virtual std::string		getName() const;
		virtual int	getGradeAuth() const;
		virtual int	getGradeExec() const;
		virtual void			beSigned(class Bureaucrat &personnel);
		virtual void			execute(Bureaucrat const &executor) const;

	private:
		const std::string	name; // target
		const int			grade_auth;
		const int			grade_exec;
		bool				is_signed;
};

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &insert);

#endif
