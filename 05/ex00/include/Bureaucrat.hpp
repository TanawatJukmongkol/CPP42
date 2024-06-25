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
		Bureaucrat(const std::string name, unsigned int grade);
		friend std::ostream &operator<<(std::ostream &stream, const Bureaucrat &insert);

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			promote(unsigned int rank);
		void			demote(unsigned int rank);

		static std::exception	GradeTooHighException();
		static std::exception	GradeTooLowException();

	private:
		const std::string	name;
		unsigned int 		grade;
};

#endif
