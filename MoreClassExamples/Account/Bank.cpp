#include <string>
#include <iostream>

#include "Account.h"

using namespace std;

int main()
{
	Account checkingAccount;

	checkingAccount.setAccountNumber(123456789);
	checkingAccount.setName("Eric's Checking");
	checkingAccount.setOwnersName("Eric Charnesky");
	checkingAccount.setAddress("UofM Dearborn, CIS 217");
	
	cout << "Account Number: " << checkingAccount.getAccountNumber() << endl;
	cout << "Name: " << checkingAccount.getName() << endl;
	cout << "Owner's Name: " << checkingAccount.getOwnersName() << endl;
	cout << "Address: " << checkingAccount.getAddress() << endl;
	cout << "Current Balance: " << checkingAccount.getBalance() << endl;

	cout << "Depoisting $1000";
	checkingAccount.deposit(1000);
	cout << "Current Balance: " << checkingAccount.getBalance() << endl;
	
	cout << "Withdrawing $500 - actually withdrew: " << checkingAccount.withdraw(500) << endl;
	cout << "Current Balance: " << checkingAccount.getBalance() << endl;
	
	cout << "Withdrawing $1000 - actually withdrew: " << checkingAccount.withdraw(1000) << endl;
	cout << "Current Balance: " << checkingAccount.getBalance() << endl;

	system("pause");

	return 0;
}