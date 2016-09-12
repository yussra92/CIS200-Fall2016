#include <iostream>
#include <string>
#include <array>
using namespace std;

void Reverse(string&);
void RecursiveReverse(string&, int);

int main()
{
	const int NUMBER_OF_TEST_CASES = 5;
	string testCases[NUMBER_OF_TEST_CASES] = {
		"Apples", "Bananas", "C", "", "abcdefghijklmnopqrstuvwxyz"
	};

	for (int index = 0; index < NUMBER_OF_TEST_CASES; index++)
	{
		cout << testCases[index] << " reversed is: ";
		Reverse(testCases[index]);
		cout << testCases[index] << endl;
	}
	
	string input;
	cout << "Please enter a string to reverse:" << endl;
	cin >> input;
	Reverse(input);
	cout << input << endl;
	return 0;
}

void Reverse(string& toReverse)
{
	RecursiveReverse(toReverse, 0);
}

void RecursiveReverse(string& toReverse, int position)
{
	if (position >= (int)toReverse.length() / 2)
	{
		return;
	}

	char temp = toReverse.at(position);
	toReverse.at(position) = toReverse.at(toReverse.length() - position - 1);
	toReverse.at(toReverse.length() - position - 1) = temp;
	RecursiveReverse(toReverse, position + 1);
}