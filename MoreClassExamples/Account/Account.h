#include <string>
using namespace std;
#pragma once
class Account
{
public:
	Account();
	double getBalance();
	void deposit(double money);
	double withdraw(double money);
	string getName();
	int getAccountNumber();
	string getAddress();
	void setAddress(string address);
	void setName(string name);
	void setAccountNumber(int accountNumber);
	string getOwnersName();
	void setOwnersName(string ownersName);

private:
	double balance;
	string name;
	int accountNumber;
	string ownersName;
	string address;
};