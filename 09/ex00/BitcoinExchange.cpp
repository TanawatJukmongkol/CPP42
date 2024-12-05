#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

BitcoinExchange::BitcoinExchange(std::string db_path)
{
	std::ifstream	db_file;
	std::string		tmp;

	db_file.open(db_path.c_str());
	if (db_file.fail())
		throw BitcoinExchange::databaseFailure();
	// Skip first line
	db_file >> tmp;
	if (!db_file)
		throw BitcoinExchange::databaseEmpty();
	while (db_file)
	{
		db_file >> tmp;
		size_t sep = tmp.find(",");
		std::string second_half = tmp.substr(sep + 1, tmp.length());
		if (sep == std::string::npos || second_half.find(",") != std::string::npos)
			throw invalidDatabase();
		key_val_t	tmp_tuple;
		tmp_tuple.first = tmp.substr(0, sep);
		tmp_tuple.second = std::strtod(second_half.c_str(), NULL);
		if (tmp_tuple.second < 0)
			throw invalidDatabase();
		_database.push_back(tmp_tuple);
	}
}

double	BitcoinExchange::getExchangeRate(std::string date_iso_8601)
{
	vec_pair_t::iterator i;
	// Read back to front, skip first row.
	for (i = _database.end() - 1; i != _database.begin() + 1; i--)
	{
		// std::string year = i->first.substr(0, i->first.find("-"));
		if (i->first <= date_iso_8601)
			break ;
	}
	// std::cout << i->first << ":" << i->second << std::endl;
	return i->second;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &assignment)
{
	(void)assignment;
	return *this;
}

std::exception	BitcoinExchange::databaseFailure()
{
	std::runtime_error	exception("Error: could not open exchange rate database.");
	throw exception;
}

std::exception	BitcoinExchange::databaseEmpty()
{
	std::runtime_error	exception("Error: database is empty.");
	throw exception;
}

std::exception	BitcoinExchange::invalidDatabase()
{
	std::runtime_error	exception("Error: invalid or corrupted database.");
	throw exception;
}
