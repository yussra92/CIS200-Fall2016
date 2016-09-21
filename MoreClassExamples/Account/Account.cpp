#include <string>
#include "Account.h"

using namespace std;

Account::Account()
{
	balance = 0;
	name = "";
	address = "";
	ownersName = "";
	accountNumber = -1;
}

double Account::getBalance()
{
	return balance;
}

void Account::deposit(double money)
{
	balance += money;
}

double Account::withdraw(double money)
{
	if (balance >= money)
	{
		balance -= money;
		return money;
	}
	else
	{
		double actuallyWithdrawn = balance;
		balance = 0;
		return actuallyWithdrawn;
	}
}

string Account::getName()
{
	return name;
}

int Account::getAccountNumber()
{
	return accountNumber;
}

string Account::getAddress()
{
	return address;
}

void Account::setAddress(string a )
{
	address = a;
}

void Account::setName(string n)
{
	name = n;
}

void Account::setAccountNumber(int accountNum )
{
	accountNumber = accountNum;
}

string Account::getOwnersName()
{
	return ownersName;
}

void Account::setOwnersName(string name )
{
	ownersName = name;
}
