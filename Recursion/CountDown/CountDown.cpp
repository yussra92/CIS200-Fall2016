#include <iostream>
#include <string>
#include <array>
using namespace std;

void IsPrime(int startingNumber)
{
	if (startingNumber == 0)
	{
		cout << startingNumber << endl;
	}
	else
	{
		cout << startingNumber << endl;
		IsPrime(startingNumber - 1);
	}
}

int main()
{
	int number = 10;

	IsPrime(number);

	string input;
	cin >> input;

	return 0;

}