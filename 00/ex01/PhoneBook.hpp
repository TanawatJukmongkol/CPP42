
#ifndef BOOK_HPP
# define BOOK_HPP

# include <cstdio>
# include <sstream>
# include "Contact.hpp"

class Book {
	private:
		int		_indx;
		Contact	_contacts[8];
	public:
		Book ();

		Contact	*get();
		Contact	*get(int indx);
		void	set_fname(std::string fname);
		void	set_lname(std::string lname);
		void	set_nickname(std::string nick);
		void	set_phoneNbr(std::string phone);
		void	set_secret(std::string secret);

		void	push();
};

#endif
