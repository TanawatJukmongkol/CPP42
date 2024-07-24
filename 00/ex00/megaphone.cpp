#include <iostream>
#include <string>

int main (int argc, char **argv) {
	size_t		str_len;
	std::string	str;

	// Default noize REEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!!!
	if (argc < 2)
	{
		std::cout << "* LOUND AND UNBAEARABE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	// Join argv
	for (int i = 1; i < argc; i++)
	{
		// If argv is empty, exit with error
		if (!*argv[1])
		{
			std::cerr << "FATAL ERROR: MEGAPHONE RECIEVED AN INVALID SIGNAL! (ASCII \\0)" << std::endl;
			return 1;
		}
		str.append(argv[i]);
	}
	// Convert to upper case
	str_len = str.length();
	for (size_t i = 0; i < str_len; i++)
		str[i] = toupper(str[i]);
	std::cout << str << std::endl;
	return 0;
}

