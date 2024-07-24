#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &assignment);
		Bureaucrat(const std::string name, int grade);

		std::string		getName() const;
		int				getGrade() const;
		void			promote(int rank);
		void			demote(int rank);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		int 				grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &insert);

#endif
