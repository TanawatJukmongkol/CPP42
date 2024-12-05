#include "RPN.hpp"
#include <exception>
#include <iostream>

int main (int argc, char **argv)
{
	RPN	dinnerbone_polish_cow;

	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		if (!argv[1][0])
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		std:: cout << dinnerbone_polish_cow.evaluate(std::string(argv[1])) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
