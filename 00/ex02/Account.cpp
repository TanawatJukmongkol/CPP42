
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0,
	Account::_totalAmount = 0,
	Account::_totalNbDeposits = 0,
	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char buffer	[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime (buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

}

Account::~Account ()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawl)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	if (withdrawl > _amount)
	{
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:" << withdrawl << ";";
	_amount -= withdrawl;
	_totalAmount -= withdrawl;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return true;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::getNbAccounts() {return _nbAccounts;}
int	Account::getTotalAmount() {return _totalAmount;}
int	Account::getNbDeposits() {return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals() {return Account::_totalNbWithdrawals;}


int Account::checkAmount() const
{
	return _amount;
}
