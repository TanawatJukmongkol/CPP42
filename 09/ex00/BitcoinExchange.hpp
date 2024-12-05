#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <string>
#include <vector>

// An array of tuples, basically.
typedef std::pair<std::string, double>	key_val_t;
typedef std::vector< key_val_t >		vec_pair_t;

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string db_path);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &assignment);
		double	getExchangeRate(std::string date_iso_8601);

		static std::exception	databaseFailure();
		static std::exception	databaseEmpty();
		static std::exception	invalidDatabase();
	private:
		vec_pair_t	_database;
};

#endif
