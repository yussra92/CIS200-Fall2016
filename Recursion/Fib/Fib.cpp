#include <iostream>
#include <string>
#include <array>
using namespace std;


int Fibonacci( int nthPosition )
{
	if (nthPosition <= 2)
	{
		return 1;
	}
	else
	{
		return(Fibonacci(nthPosition - 1) + Fibonacci(nthPosition - 2));
	}
}

int main()
{
	int nthFibonacciNumber = 43;

	cout << "The " << nthFibonacciNumber << " in the Fib sequence is: " << Fibonacci(nthFibonacciNumber) << endl;
	string input;
	cin >> input;

	return 0;

}