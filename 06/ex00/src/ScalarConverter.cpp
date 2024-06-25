#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ostream>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destroyed" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &assignment)
{
	(void)(assignment);
	return *this;
}


bool is_float(std::string literal_string)
{
	return literal_string.find('f') != std::string::npos;
}

bool is_decimal(std::string literal_string)
{
	return literal_string.find('.') != std::string::npos;
}

bool is_valid_num(std::string literal_string)
{
	const char *lit_cstr = literal_string.c_str();
	bool found_decimal = false;
	bool found_float = false;
	// check duplicate, empty literal or only symbol
	if ((is_decimal(literal_string) && literal_string.find('.') != literal_string.find_last_of('.'))
		|| (is_float(literal_string) && literal_string.find('f') != literal_string.find_last_of('f'))
		|| literal_string.length() == 0
		|| (literal_string.length() == 1 && std::isdigit(lit_cstr[0]) == 0))
		return false;
	for (size_t i = 0; i < literal_string.length(); i++)
	{
		if (i == 0 && (lit_cstr[0] == '-' || lit_cstr[0] == '+'))
			continue ;
		if (lit_cstr[i] == '.')
		{
			found_decimal = true;
			continue;
		}
		if (found_decimal && lit_cstr[i] == 'f')
		{
			found_float = true;
			continue;
		}
		if (std::isdigit(lit_cstr[i]) == 0 || found_float)
			return false;
	}
	return true;
}

void	print_nan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	print_inf(std::string literal_string)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal_string.find("-inf") != std::string::npos) {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void print_char(std::string literal_string)
{
	char c = literal_string.c_str()[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_int(std::string literal_string)
{
	long nbr = std::strtol(literal_string.c_str(), NULL, 10);

	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		int nbr_int = static_cast<int>(nbr);
		if (std::isprint(nbr))
			std::cout << "char: " << static_cast<char>(nbr_int) << std::endl;
		else 
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << nbr_int << std::endl;
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << static_cast<float>(nbr_int) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr_int) << std::endl;
	}
}

void print_float(std::string literal_string)
{
	float nbr = std::strtof(literal_string.c_str(), NULL);

	if (std::isprint(nbr))
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << nbr << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

void print_double(std::string literal_string)
{
	double nbr = std::strtod(literal_string.c_str(), NULL);

	if (std::isprint(nbr))
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << nbr << std::endl;
}

void ScalarConverter::convert(std::string literal_string)
{
	if (literal_string == "nan"
		|| literal_string == "nanf"
	)
		print_nan();
	else if (
		literal_string == "inf"
		|| literal_string == "inff"
		|| literal_string == "+inf"
		|| literal_string == "-inf"
		|| literal_string == "+inff"
		|| literal_string == "-inff"
	)
		print_inf(literal_string);
	else if (is_valid_num(literal_string))
	{
		if (is_float(literal_string))
			print_float(literal_string);
		else if (is_decimal(literal_string))
			print_double(literal_string);
		else
			print_int(literal_string);
	}
	else if (literal_string.length() == 1)
		print_char(literal_string);
	else
		std::cout << "This literal makes no sense." << std::endl;
}
