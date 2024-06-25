#include "../include/RPN.hpp"
#include <exception>
#include <iostream>

int main (int argc, char **argv)
{

	if (argc != 2)
	{
		if (argc != 2)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	RPN	dinnerbone_polish_cow;

	try {
		std:: cout << dinnerbone_polish_cow.evaluate(argv[1]) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error" << std::endl;
		// std::cerr << "What: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
