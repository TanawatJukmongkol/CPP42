#include "BitcoinExchange.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

// The plan: Plan out what STLs to use for each question...
// 1) std::pair, std::vector [/]
// 2) std::stack
// 3) std::list, std::deque

bool is_valid_num (std::string literal)
{
	bool is_in = false;
	bool found_negative = false;
	bool found_peroid = false;

	for (size_t i = 0; i < literal.length(); i++)
	{
		// std::cout << "vn: " << i << ": " << literal[i] << std::endl;
		if (literal[i] == ' ' || (literal[i] >= '\n' && literal[i] <= '\r'))
		{
			if (is_in)
				return false;
			continue ;
		}
		if (literal[i] == '-')
		{
			if (found_negative || is_in)
				return false;
			found_negative = true;
		}
		else if (literal[i] == '.')
		{
			if (found_peroid)
				return false;
			found_peroid = true;
		}
		if (std::isdigit(literal[i]))
			is_in = true;
	}
	return true;
}

int main (int argc, char **argv)
{
	try {
		std::ifstream	file;
		BitcoinExchange	exchange(std::getenv("EXCHANGE_DB") ? std::getenv("EXCHANGE_DB") : "./data.csv");

		if (argc != 2)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 1;
		}
		file.open(argv[1]);
		if (file.fail())
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 1;
		}
		std::string str;

		if(!std::getline(file, str))
			throw BitcoinExchange::databaseEmpty();
		while (std::getline(file, str))
		{
			key_val_t	value;

			if (str.find("|") == std::string::npos)
			{
				std::cerr << "Error: bad input => " << str << std::endl;
				continue ;
			}
			value.first = str.substr(0, std::min(str.find("|"), str.find(" ")));
			std::string rate = str.substr(str.find("|") + 1, str.length());
			if (!is_valid_num(rate))
			{
				std::cerr << "Error: bad input => " << str << std::endl;
				continue ;
			}
			value.second = std::strtod(rate.c_str(), NULL);
			double btc_amount = exchange.getExchangeRate(value.first) * value.second;
			if (std::signbit(value.second))
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue ;
			}
			if (value.second > INT_MAX)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue ;
			}
			std::cout << value.first
					  << " => "
					  << value.second
					  << " = "
					  << btc_amount << std::endl;
		}
		// std::cout << exchange.getExchangeRate("2011-02-10") << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Fatal: " << e.what() << std::endl;
		return 255;
	}

	return 0;
}
