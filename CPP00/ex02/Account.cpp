#include "Account.hpp"
#include <iostream>


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

// 타임스탬프 어떻게 찍지?
void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
}

// 왜 static을 쓸 수 없지?
//static void	Account::displayAccountsInfos(void)
/*
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
}

// 뒤에 const붙은건 뭐지?
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
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _totalAmount;
	std::cout << ";nb_deposits:" << _nbWithdrawals << std::endl;
}

/*
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool	Account::makeWithdrawal( int withdrawal )
{
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

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _totalAmount;
	std::cout << ";nb_withdrawals:";

	if (flag)
		std::cout << _nbWithdrawals << std::endl;
	else
		std::cout << "refused" << std::endl;

	return (flag);
}

/* 생성자
[19920104_091532] index:0;amount:42;created
*/
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
[19920104_091532] index:0;amount:47;closed
*/
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" <<  std::endl;

	// static변수 수정 (보충필요)
	// _nbAccounts--;
	// _totalAmount -= _amount;
}