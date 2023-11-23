
#include "PhoneBook.hpp"

Book::Book () {
	std::cout << "The PhoneBook project! (TM)" << std::endl;
	std::cout << "Availible commands:" << std::endl;
	std::cout << "ADD: Adds a user to Phonebook." << std::endl;
	std::cout << "SEARCH: Searches the user." << std::endl;
	std::cout << "EXIT (Or [ctrl] + [D]): Exits the program." << std::endl;
	_indx = 0;
}

Contact	*Book::get() {
	return &_contacts[_indx];
}

Contact	*Book::get(int indx) {
	if (indx < 0 || indx >= 8 || _contacts[indx].empty())
		return (NULL);
	return &_contacts[indx];
}

void	Book::set_fname(std::string fname) {
	_contacts[_indx].set_firstname(fname);
}
void	Book::set_lname(std::string lname) {
	_contacts[_indx].set_lastname(lname);
}
void	Book::set_nickname(std::string nick) {
	_contacts[_indx].set_nickname(nick);
}
void	Book::set_phoneNbr(std::string phone) {
	_contacts[_indx].set_phonenbr(phone);
}
void	Book::set_secret(std::string secret) {
	_contacts[_indx].set_secret(secret);
}

void	Book::push() {
	if (_contacts[_indx].empty())
	{
		std::cerr << "Contact is not complete! Cannot add the user to Phonebook. Please re-edit the contact again." << std::endl; 
		return ;
	}
	std::cout << "Added user \"";
	std::cout << _contacts[_indx].get_nickname();
	std::cout << "\" to phonebook at index ";
	std::cout << _indx + 1 << "." << std::endl;
	_indx++;
	if (_indx == 8)
		_indx = 0;
}
