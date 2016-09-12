#include <iostream>
#include <string>
#include <array>
using namespace std;

void ReverseRecursive(string wordToReverse, int position);
void Reverse(string wordToReverse);


void ReverseRecursive(string wordToReverse, int position)
{
	// base case
	if (position == 0)
	{
		cout << wordToReverse.at(position);
	}

	// complex case
	else
	{
		cout << wordToReverse.at(position);
		ReverseRecursive(wordToReverse, position - 1);
	}
}

void Reverse(string wordToReverse)
{
	ReverseRecursive(wordToReverse, wordToReverse.length() - 1);
}



int main()
{
	string wordToReverse = "race car";

	cout << wordToReverse << " backwards is: ";
	Reverse(wordToReverse);
	cout << endl;

	string input;
	cin >> input;

	return 0;

}