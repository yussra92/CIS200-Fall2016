#include <iostream>
#include <string>
#include <array>
using namespace std;


int Fib( int nthPosition )
{
	if (nthPosition <= 2)
	{
		return 1;
	}
	else
	{
		return(Fib(nthPosition - 1) + Fib(nthPosition - 2));
	}
}

int main()
{
	int nthFibNumber = 43;

	cout << "The " << nthFibNumber << " in the Fib sequence is: " << Fib(nthFibNumber) << endl;
	string input;
	cin >> input;

	return 0;

}