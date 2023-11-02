
#include "PhoneBook.hpp"

PhoneBook::PhoneBook () {
	std::cout << "The PhoneBook project! (TM)" << std::endl;
	std::cout << "Availible commands:" << std::endl;
	std::cout << "ADD: Adds a user to Phonebook." << std::endl;
	std::cout << "SEARCH: Searches the user." << std::endl;
	std::cout << "EXIT (Or [ctrl] + [D]): Exits the program." << std::endl;
	_indx = 0;
}

Contact	*PhoneBook::get() {
	return &_contacts[_indx];
}

Contact	*PhoneBook::get(int indx) {
	if (indx < 0 || indx >= 8 || _contacts[indx].empty())
		return (NULL);
	return &_contacts[indx];
}

void	PhoneBook::set_fname(std::string fname) {
	_contacts[_indx].first_name = fname;
}
void	PhoneBook::set_lname(std::string lname) {
	_contacts[_indx].last_name = lname;
}
void	PhoneBook::set_nickname(std::string nick) {
	_contacts[_indx].nick_name = nick;
}
void	PhoneBook::set_phoneNbr(std::string phone) {
	_contacts[_indx].phone_nbr = phone;
}
void	PhoneBook::set_secret(std::string secret) {
	_contacts[_indx].set_secret(secret);
}

void	PhoneBook::push() {
	if (_contacts[_indx].empty())
	{
		std::cerr << "Contact is not complete! Cannot add the user to Phonebook. Please re-edit the contact again." << std::endl; 
		return ;
	}
	std::cout << "Added user \"";
	std::cout << _contacts[_indx].nick_name;
	std::cout << "\" to phonebook at index ";
	std::cout << _indx + 1 << "." << std::endl;
	_indx++;
	if (_indx == 8)
		_indx = 0;
}
