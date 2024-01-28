#include "Account.hpp"
#include <cstdio>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << ";" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount" << this->checkAmount();
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:";
	if (this->_amount - withdrawal < 0)
		std::cout << "refused" << std::endl;
	else
	{
		this->_nbWithdrawals++;
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->checkAmount();
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}
	return true;
}

int	Account::checkAmount() const
{
	return this->_amount;
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";wthdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t	today;
	std::tm		*t;

	today = time(NULL);
	t = std::localtime(&today);
	std::cout << "[" << t->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << t->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_sec;
	std::cout << "] ";
}
