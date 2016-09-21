#include <string>
#include <iostream>

#include "Account.h"

using namespace std;

const int NUMBER_OF_ACCOUNTS = 3;

char displayMenuAndReturnChoice()
{
	cout << "Please pick an option: " << endl;
	cout << "B: Balance inquiry" << endl;
	cout << "D: Deposit money" << endl;
	cout << "W: Withdraw money" << endl;
	cout << "Q: Quit this crappy ATM" << endl;
	char choice;
	cin >> choice;
	return choice;
}

int main()
{
	Account accounts[NUMBER_OF_ACCOUNTS];

	for (int index = 0; index < NUMBER_OF_ACCOUNTS; index++)
	{
		accounts[index].setAccountNumber(index);
		accounts[index].setName("Eric's Checking");
		accounts[index].setOwnersName("Eric Charnesky");
		accounts[index].setAddress("UofM Dearborn, CIS 217");
	}

	for (int index = 0; index < NUMBER_OF_ACCOUNTS; index++)
	{
		cout << "Account Number: " << accounts[index].getAccountNumber() << endl;
		cout << "Name: " << accounts[index].getName() << endl;
		cout << "Owner's Name: " << accounts[index].getOwnersName() << endl;
		cout << "Address: " << accounts[index].getAddress() << endl;
		cout << "Current Balance: " << accounts[index].getBalance() << endl;
		cout << endl << endl;
	}

	int accountNumber;
	cout << "Please enter an account number (0,1,2)" << endl;
	cin >> accountNumber;

	char choice = displayMenuAndReturnChoice();
	while ( choice != 'Q')
	{
		if (choice == 'B')
		{
			cout << "Balance of account number: " << accountNumber << " : $" << accounts[accountNumber].getBalance() << endl;
		}
		else if (choice == 'D')
		{
			cout << "How much did you want to deposit?" << endl;
			double deposit;
			cin >> deposit;
			accounts[accountNumber].deposit(deposit);
		}
		else if (choice == 'W')
		{
			cout << "How much did you want to withdraw?" << endl;
			double withdraw;
			cin >> withdraw;
			cout << "Actually withdrew: $" << accounts[accountNumber].withdraw(withdraw) << endl;
		}
		else if (choice == 'Q')
		{
			break;
		}
		else
		{
			cout << choice << " is not a valid choice, please try again" << endl;
		}

		choice = displayMenuAndReturnChoice();
	}

	
	system("pause");

	return 0;
}