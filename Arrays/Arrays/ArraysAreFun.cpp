#include <iostream>
#include <string>

using namespace std;


int main()
{
	int studentIDs[7][6]
	{
		{ 2, 6, 42, 6456, 12, 0},
		{ 1, 2, 3, 4, 5, 6},
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 }
	};


	int dollarsInPocket[7][6];

	for (int row = 0; row < 7; row++)
	{
		for (int collum = 0; collum < 6; collum++)
		{
			dollarsInPocket[row][collum] = row + collum;
		}
	}

	dollarsInPocket[6][4] = 100;

	for (int row = 6; row >= 0; row--)
	{
		cout << row << "|\t";
		for (int collum = 0; collum < 6; collum++)
		{
			cout << dollarsInPocket[row][collum] << '\t';
		}
		cout << endl;
	}
	cout << "\t------------------------------------------" << endl;
	cout << '\t';
	for (int collum = 0; collum < 6; collum++)
	{
		cout << collum << '\t';
	}
	cout << endl;

	string input;
	cin >> input;

	return 0;
}