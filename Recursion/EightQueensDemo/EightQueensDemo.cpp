#include <iostream>

using namespace std;

void print();
void placeQueen();

const char QUEEN = 'Q';
char board[8][8];
int numberOfQueensOnTheBoard = 0;
int numberOfQueensTried = 0;
bool canPlaceQueen(int row, int col);

int main()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = ' ';
		}
	}

	placeQueen();

	cout << endl << endl << "Total number of queens tried: " << numberOfQueensTried << endl;

	char c;
	cin >> c;
	return 0;
}

void placeQueen()
{
	if (numberOfQueensOnTheBoard == 8)
	{
		print();
	}
	else
	{
		for (int row = 0; row < 8 && numberOfQueensOnTheBoard != 8; row++)
		{
			if (canPlaceQueen(row, numberOfQueensOnTheBoard))
			{
				board[row][numberOfQueensOnTheBoard] = QUEEN;
				numberOfQueensOnTheBoard++;
				numberOfQueensTried++;
				
				if (numberOfQueensOnTheBoard == 8)
				{
					print();
				}
				else
				{
					placeQueen();
				}
				if (numberOfQueensOnTheBoard != 8)
				{
					numberOfQueensOnTheBoard--;
					board[row][numberOfQueensOnTheBoard] = ' ';
				}
			}
		}
	}
}

bool canPlaceQueen(int row, int col)
{
	if (col == 0)
	{
		return true;
	}

	// check row
	for (int currentCol = col - 1; currentCol >= 0; currentCol--)
	{
		if (board[row][currentCol] == QUEEN)
		{
			return false;
		}
	}

	int currentCol;
	int currentRow;
	// check up and right diagonal
	for (currentCol = col - 1, currentRow = row + 1; 
		currentCol >= 0 && currentRow <= 7; 
		currentCol--, currentRow++)
	{
		if (board[currentRow][currentCol] == QUEEN)
		{
			return false;
		}
	}

	// check back and right diagonal
	for (currentCol = col - 1, currentRow = row - 1;
		currentCol >= 0 && currentRow >= 0;
		currentCol--, currentRow--)
	{
		if (board[currentRow][currentCol] == QUEEN)
		{
			return false;
		}
	}

	return true;
}

void print()
{
	for (int row = 7; row >= 0; row--)
	{
		cout << "  - - - - - - - -" << endl;
		cout << row << "|";
		for (int collum = 0; collum <= 7; collum++)
		{
			cout << board[row][collum] << "|";
		}
		cout << endl;
	}
	cout << "  - - - - - - - -" << endl;
	cout << "  0 1 2 3 4 5 6 7" << endl;

	cout << endl;
}