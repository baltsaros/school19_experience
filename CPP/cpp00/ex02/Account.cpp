#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";";
	std::cout << std::endl;
	return ;
}

Account::Account(int initial_deposit){
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void){
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit){
	_totalNbDeposits++;
	_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal){
	if (!withdrawal)
		return (false);
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const{
	return (_amount);
}

void	Account::displayStatus(void) const{
	this->_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void){
	time_t	now;
	tm		*date;

	now = time(0);
	date = localtime(&now);
	std::cout << "[";
	std::cout << 1900 + date->tm_year;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << date->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_sec;
	std::cout << "]";
}
