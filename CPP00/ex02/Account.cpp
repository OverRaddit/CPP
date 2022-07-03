#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip> // setw
// =============================================================================
// Static variables
// =============================================================================

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;


// =============================================================================
// Getter & Setter
// =============================================================================

int		Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int		Account::getTotalAmount( void )
{
	return _totalAmount;
}
int		Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

// =============================================================================
// Method
// =============================================================================

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(nullptr);
	std::tm *tm = std::localtime(&result);

	std::cout << std::setfill('0');
	std::cout << "[";
	std::cout << tm->tm_year + 1900;
	std::cout << std::setw(2) << tm->tm_mon << std::setw(2) << tm->tm_mday << "_";
	std::cout << std::setw(2) << tm->tm_hour;
	std::cout << std::setw(2) << tm->tm_min << std::setw(2) << tm->tm_sec;
	std::cout << "] ";
	std::cout << std::setfill(' ');
	//[yyyymmdd_hhmmss] 122329_17303
	//std::cout << "[19920104_091532] ";
}

/*
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/*
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/*
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void	Account::makeDeposit( int deposit )
{
	// 개인정보 갱신
	_amount += deposit;
	_nbDeposits++;

	// 공용정보 갱신
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";

	bool flag = true;
	if (_amount < withdrawal)
		flag = false;
	else
	{
		// 개인정보 갱신
		_amount -= withdrawal;
		_nbWithdrawals++;

		// 공용정보 갱신
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}

	if (flag)
		std::cout << withdrawal;
	else
	{
		std::cout << "refused" << std::endl;
		return (flag);
	}
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;


	return (flag);
}

Account::Account( int initial_deposit )
{
	// 개인정보
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// 공용정보
	_totalAmount += _amount;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" <<  std::endl;
}


/* 소멸자
vector안에서의 소멸순서는 vector가 구현된 표준 라이브러리 따라 다르다
아마 맥이랑 우분투사이의 라이브러리 구현따라 다른것 때문에 역순으로 나오지 않았나 생각
*/
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" <<  std::endl;

	// static변수 수정
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}