#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) :
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0) {
		Account::_nbAccounts++;
		return ;
	}

Account::Account( int initial_deposit ) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0){
		Account::_nbAccounts++;
		Account::_totalAmount += _amount;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "created" << std::endl;
		return ;
	}

Account::~Account( void ) {
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void ) {
	std::time_t	rawTime;
	struct tm	*timeInfo;

	std::time(&rawTime);
	timeInfo = std::localtime(&rawTime);

	std::cout << "[" << std::put_time(timeInfo, "%Y%m%d_%H%M%S") << "] ";
	return ;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" <<_amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount()	<< ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}