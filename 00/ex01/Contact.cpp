
#include "Contact.hpp"

bool	Contact::empty() {
	return (
		_first_name.empty()
		|| _last_name.empty()
		|| _nick_name.empty()
		|| _phone_nbr.empty()
		|| _secret.empty()
	);
}

void	Contact::set_firstname (std::string fname) {
	if (fname.empty())
		return ;
	_first_name = fname;
}

void	Contact::set_lastname (std::string lname) {
	if (lname.empty())
		return ;
	_last_name = lname;
}

void	Contact::set_nickname (std::string nick) {
	if (nick.empty())
		return ;
	_nick_name = nick;
}

void	Contact::set_phonenbr (std::string nbr) {
	if (nbr .empty())
		return ;
	_phone_nbr = nbr;
}

void	Contact::set_secret (std::string secret) {
	if (secret.empty())
		return ;
	_secret = secret;
}

std::string	Contact::get_firstname () {
	return Contact::_first_name;
}

std::string	Contact::get_lastname () {
	return Contact::_last_name;
}

std::string	Contact::get_nickname () {
	return Contact::_nick_name;
}

std::string	Contact::get_phonenbr () {
	return Contact::_phone_nbr;
}

std::string	Contact::get_secret () {
	return Contact::_secret;
}

