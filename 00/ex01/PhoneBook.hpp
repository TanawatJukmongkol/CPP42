
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdio>
# include <sstream>
# include "Contact.hpp"

class PhoneBook {
	private:
		int		_indx;
		Contact	_contacts[8];
	public:
		PhoneBook ();

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
