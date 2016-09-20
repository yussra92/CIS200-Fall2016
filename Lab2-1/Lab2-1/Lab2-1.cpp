#include <iostream>

using namespace std;


const int MAX_ROWS = 3;
const int MAX_COLUMNS = 2;

int Even(int A[MAX_ROWS][MAX_COLUMNS], int length, int width);

int main()
{

	int A[MAX_ROWS][MAX_COLUMNS] = { { 3 , 2 },{ 4, 5 },{ 2, 2 } };

	cout << Even(A, MAX_ROWS, MAX_COLUMNS);
	char pause;
	cin >> pause;
	return 0;

}

int Even(int A[MAX_ROWS][MAX_COLUMNS], int length, int width)
{
	int numberOfEvenNumbersInArray = 0;
	for (int rows = 0; rows < length; rows++)
	{
		for (int col = 0; col < width; col++)
		{
			numberOfEvenNumbersInArray++;
		}
	}

	return numberOfEvenNumbersInArray;
}
