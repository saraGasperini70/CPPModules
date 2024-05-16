#include "Account.hpp"
#include <ostream>
#include <iostream>
#include <string>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
	this->_nbDeposits = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

void	Account::displayAccountsInfos( void )
{

}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits = deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > 0)
		return true;
	else
		return false;
}

int		Account::checkAmount( void ) const
{
	return this->getTotalAmount();
}

void	Account::displayStatus( void ) const
{

}
