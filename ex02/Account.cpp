#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" <<
				 "amount:" << this->_amount << ";" <<
				 "created" <<
				 std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" <<
				 "amount:" << _amount << ";" <<
				 "closed" <<
				 std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now;
	std::time(&now);

	std::tm *timestruct;
	timestruct = std::localtime(&now);
	char buffer[18];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timestruct);
	std::cout << buffer;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";" <<
				 "total:" << _totalAmount << ";" <<
				 "deposits:" << _totalNbDeposits << ";" <<
				 "withdrawals:" << _totalNbWithdrawals <<
				 std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" <<
				 "amount:" << this->_amount << ";" <<
				 "deposits:" << this->_nbDeposits << ";" <<
				 "withdrawals:" << this->_nbWithdrawals <<
				 std::endl;
}

int Account::checkAmount( void ) const
{
	int value = this->_amount;
	if (value < 0)
		return (0);
	return (value);
}

void Account::makeDeposit( int deposit )
{
	if (deposit <= 0)
	{
		return ;
	}
	int prev_amount = this->_amount;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" <<
				 "p_amount:" << prev_amount << ";" <<
				 "deposit:" << deposit << ";" <<
				 "amount:" << this->_amount << ";" <<
				 "nb_deposits:" << this->_nbDeposits <<
				 std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= 0)
		return (false);
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";" <<
					 "p_amount:" << this->_amount << ";" <<
					 "withdrawal:refused" <<
					 std::endl;
		return (false);
	}

	int prev_withdrawal = this->_amount;

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";" <<
				 "p_amount:" << prev_withdrawal << ";" <<
				 "withdrawal:" << withdrawal << ";" <<
				 "amount:" << this->_amount << ";" <<
				 "nb_withdrawals:" << this->_nbWithdrawals <<
				 std::endl;
	return (true);
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
