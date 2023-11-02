
#include "Contact.hpp"

bool	Contact::empty() {
	return (
		first_name.empty()
		|| last_name.empty()
		|| nick_name.empty()
		|| phone_nbr.empty()
		|| _secret.empty()
	);
}

void	Contact::set_secret (std::string secret) {
	if (!_secret.empty() || secret.empty())
		return ;
	_secret = secret;
}
