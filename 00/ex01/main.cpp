#include "PhoneBook.hpp"

bool	isNumber (const char *str) {
	size_t	indx = 0;
	bool	isNum = true;

	if (str[0] == '-')
		indx++;
	else if (str[0] == '+')
		indx++;
	if (!std::isdigit(str[indx]))
		return false;
	for (; str[indx]; indx++) {
		if (!std::isdigit(str[indx]))
		{
			isNum = false;
			break;
		}
	}
	return (isNum);
}

std::string toUpper(std::string str)
{
	const char	*cstr = str.c_str();
	size_t		len = str.length();

	for (size_t i = 0; i < len; i++)
		str[i] = toupper(cstr[i]);
	return (str);
}

std::string trunc10wide (std::string str)
{
	std::string s = "          ";
	int front = 10 - str.length();
	if (front < 0)
		front = 0;
	for (int i = front; i < 10; i++)
		s[i] = str[i - front];
	if (str.length() >= 10)
		s[9] = '.';
	return s;
}

int add_user(Book *pb)
{
	std::string	line;

	std::cout << "- first name -" << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, line))
		return 0;
	pb->set_fname(line);
	std::cout << "- last name -" << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, line))
		return 0;
	pb->set_lname(line);
	std::cout << "- nick name -" << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, line))
		return 0;
	pb->set_nickname(line);
	std::cout << "- phone number -" << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, line))
		return 0;
	if (isNumber(line.c_str()) && isdigit(line[0]))
		pb->set_phoneNbr(line);
	std::cout << "- secret -\n> ";
	if (!std::getline(std::cin, line))
		return 0;
	std::cout << "\033[A\33[2K\r";
	std::cout << "=[/// TOP SECRET REDACTED ///]=" << std::endl;
	pb->set_secret(line);
	if (pb->get()->empty())
	{
		std::cerr << "Opps! Looks like you've made a mistake! Please retry." << std::endl;
		return 1;
	}
	pb->push();
	return 0;
}

int	search(Book *pb)
{
	std::string	line;
	int			nbr;
	Contact		*contact;

	std::cout << "|    index |first name| last name| nick name|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::stringstream	st;
		std::string			st_num;
		if (!(contact = pb->get(i)))
			break ;
		st << i + 1;
		st >> st_num;
		std::cout << "|" << trunc10wide(st_num) << "|";
		std::cout << trunc10wide(contact->get_firstname()) << "|";
		std::cout << trunc10wide(contact->get_lastname()) << "|";
		std::cout << trunc10wide(contact->get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "== user to search (1 - 8, 0 to cancel) ==\n> ";
	if (!std::getline(std::cin, line))
		return 0;
	if (!isNumber(line.c_str())) {
		std::cout << "Invalid input! Please try again." << std::endl;
		return 1;
	}
	if ((nbr = std::atoi(line.c_str())) == 0)
		return 0;
	if (!(contact = pb->get(nbr - 1)))
	{
		if (nbr < 1 || nbr > 8)
			std::cout << "Index out of range! Please try again." << std::endl;
		else
			std::cout << "User not found." << std::endl;
		return 1;
	}
	std::cout << "Phone number: ";
	std::cout << contact->get_phonenbr() << std::endl;
	return 0;

}

void	repl(Book *pb) {
	std::string	line;
	int			mode = -1;

	while (true)
	{
		if (mode > -1)
		{
			switch (mode)
			{
				case 0: while (add_user(pb)); break;
				case 1: while (search(pb)); break;
			}
			mode = -1;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "PhoneBook > ";
			if (!std::getline(std::cin, line))
			{
				std::cout << "exiting..." << std::endl;
				break ;
			}
			line = toUpper(line);
			if (line == "ADD")
				mode = 0;
			else if (line == "SEARCH")
				mode = 1;
			else if (line == "EXIT")
			{
				std::cout << "exiting..." << std::endl;
				break ;
			}
			else
				std::cerr << "Invalid mode. Please re-select." <<std::endl;
		}
	}
}

int main () {
	Book	pb;

	repl(&pb);
	return 0;
}

