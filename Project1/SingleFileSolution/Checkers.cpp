#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
	Board();
	void reset(); //clears the board
	void addChecker(char who, int row, int col);
	int numJumps(int row, int col); // num of jumps possible from row, col
	void print(); // print the board for debugging only  
	static const char BLACK = 'B';
	static const char WHITE = 'W';
	int getFirstWhitePieceRow();
	int getFirstWhitePieceCol();

private:
	void tryToJump(int row, int col);
	bool canJumpTopRight(int row, int col);
	bool canJumpBottomRight(int row, int col);
	bool canJumpBottomLeft(int row, int col);
	bool canJumpTopLeft(int row, int col);
	char board[8][8];
	int maxJumps;
	int currentJumps;
	int firstWhitePieceRow;
	int firstWhitePieceCol;
};



int main()
{
	int numberOfTestCases;
	int numberOfWhitePieces;
	int numberOfBlackPieces;
	int row;
	int col;

	cin >> numberOfTestCases;

	vector<Board> boards(numberOfTestCases);

	for (int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++)
	{
		cin >> numberOfWhitePieces >> numberOfBlackPieces;

		for (int whitePiecesOnBoard = 0; whitePiecesOnBoard < numberOfWhitePieces; whitePiecesOnBoard++)
		{
			cin >> row >> col;
			boards.at(testCaseNumber).addChecker(Board::WHITE, row, col);
		}
		for (int blackPiecesOnBoard = 0; blackPiecesOnBoard < numberOfBlackPieces; blackPiecesOnBoard++)
		{
			cin >> row >> col;
			boards.at(testCaseNumber).addChecker(Board::BLACK, row, col);
		}
	}

	for (int boardIndex = 0; boardIndex < boards.size(); boardIndex++)
	{
		cout << "the number of jumps is " << boards.at(boardIndex).numJumps(boards.at(boardIndex).getFirstWhitePieceRow(), boards.at(boardIndex).getFirstWhitePieceCol()) << endl;
	}
}

Board::Board()
{
	reset();
	maxJumps = 0;
	currentJumps = 0;
	firstWhitePieceCol = -1;
	firstWhitePieceRow = -1;
}

void Board::reset()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = ' ';
		}
	}
}

void Board::addChecker(char who, int row, int col)
{
	if (row < 0 || row > 7 || col < 0 || col > 7)
	{
		//cout << "INVALID location: " << row << " " << col << endl;
		return;
	}
	board[row][col] = who;
	if (who == WHITE && firstWhitePieceRow == -1 && firstWhitePieceCol == -1)
	{
		firstWhitePieceRow = row;
		firstWhitePieceCol = col;
	}
}

int Board::numJumps(int row, int col)
{
	if (board[row][col] == Board::WHITE)
	{
		currentJumps = 0;
		addChecker(' ', row, col);
		tryToJump(row, col);
		addChecker(WHITE, row, col);
	}
	return maxJumps;
}

void Board::tryToJump(int row, int col)
{
	if (canJumpTopRight(row, col))
	{
		currentJumps++;
		addChecker(' ', row + 1, col + 1);
		tryToJump(row + 2, col + 2);
		if (currentJumps > maxJumps)
		{
			maxJumps = currentJumps;
		}
		addChecker(BLACK, row + 1, col + 1);
		currentJumps--;
	}
	if (canJumpBottomRight(row, col))
	{
		currentJumps++;
		addChecker(' ', row - 1, col + 1);
		tryToJump(row - 2, col + 2);
		if (currentJumps > maxJumps)
		{
			maxJumps = currentJumps;
		}
		addChecker(BLACK, row - 1, col + 1);
		currentJumps--;
	}
	if (canJumpBottomLeft(row, col))
	{
		currentJumps++;
		addChecker(' ', row - 1, col - 1);
		tryToJump(row - 2, col - 2);
		if (currentJumps > maxJumps)
		{
			maxJumps = currentJumps;
		}
		addChecker(BLACK, row - 1, col - 1);
		currentJumps--;
	}
	if (canJumpTopLeft(row, col))
	{
		currentJumps++;
		addChecker(' ', row + 1, col - 1);
		tryToJump(row + 2, col - 2);
		if (currentJumps > maxJumps)
		{
			maxJumps = currentJumps;
		}
		addChecker(BLACK, row + 1, col - 1);
		currentJumps--;
	}
}


void Board::print()
{
	cout << "  0 1 2 3 4 5 6 7" << endl;
	for (int row = 7; row >= 0; row--)
	{
		cout << "  ---------------" << endl;
		cout << row << "|";
		for (int column = 0; column < 8; column++)
		{
			cout << board[row][column] << "|";
		}
		cout << row << endl;
	}
	cout << "  ---------------" << endl;
	cout << "  0 1 2 3 4 5 6 7" << endl;
}

int Board::getFirstWhitePieceRow()
{
	return firstWhitePieceRow;
}

int Board::getFirstWhitePieceCol()
{
	return firstWhitePieceCol;
}



bool Board::canJumpTopRight(int row, int col)
{
	return (row <= 5 && col <= 5 && board[row + 1][col + 1] == BLACK && board[row + 2][col + 2] == ' ');
}

bool Board::canJumpBottomRight(int row, int col)
{
	return (row >= 2 && col <= 5 && board[row - 1][col + 1] == BLACK && board[row - 2][col + 2] == ' ');
}

bool Board::canJumpBottomLeft(int row, int col)
{
	return (row >= 2 && col >= 2 && board[row - 1][col - 1] == BLACK && board[row - 2][col - 2] == ' ');
}

bool Board::canJumpTopLeft(int row, int col)
{
	return (row <= 5 && col >= 2 && board[row + 1][col - 1] == BLACK && board[row + 2][col - 2] == ' ');
}