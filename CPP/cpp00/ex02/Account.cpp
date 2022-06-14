#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
	std::cout << Account::_displayTimestamp;
	std::cout << " accounts:" << Account::getNbAccounts << ";";
	std::cout << "total:" << Account::getTotalAmount << ";";
	std::cout << "deposits:" << Account::getNbDeposits << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals << ";";
	return ;
}

Account::Account(int initial_deposit){
	std::cout << this->_displayTimestamp;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void){
	std::cout << this->_displayTimestamp;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

void	makeDeposit(int deposit){
	_totalNbDeposits++;
	_totalAmount += deposit;
	return ;
}

void	Account::_displayTimestamp(void){
	time_t	now;
	tm		*date;

	now = time(0);
	date = localtime(&now);
	std::cout << "[";
	std::cout << 1900 + date->tm_year;
	if (date->tm_mon + 1 > 9)
		std::cout << date->tm_mon + 1;
	else
		std::cout << "0" << date->tm_mon + 1;
	if (date->tm_mday > 9)
		std::cout << date->tm_mday;
	else
		std::cout << "0" << date->tm_mon;
	std::cout << "_";
	std::cout << date->tm_hour;
	std::cout << date->tm_min;
	std::cout << date->tm_sec;
	std::cout << "]";
}
