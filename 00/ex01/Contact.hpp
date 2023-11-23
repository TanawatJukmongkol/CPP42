
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class Contact {
	public:
		bool	empty();

		void	set_firstname (std::string secret);
		void	set_lastname (std::string secret);
		void	set_nickname (std::string secret);
		void	set_phonenbr (std::string secret);
		void	set_secret (std::string secret);

		std::string	get_firstname ();
		std::string	get_lastname ();
		std::string	get_nickname ();
		std::string	get_phonenbr ();
		std::string	get_secret ();
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_nbr;
		std::string	_secret;
};

#endif
