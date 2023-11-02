
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class Contact {
	private:
		std::string	_secret;
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_nbr;

		bool	empty();
		void	set_secret (std::string secret);
};

#endif
