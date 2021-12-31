#include <iostream>
#include <fstream>
using namespace std;

// matrix is two dimensional array. You should transposition matrix
void transposition(int rows, int cols, int **matrix) {
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			cout << matrix[i][j];
			if (i != rows - 1) cout << " ";
		}
		cout << endl;
	}
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	
	int rows;
	int cols;
	ifs >> rows;
	ifs >> cols;
	int** matrix = new int*[rows];
	try
	{
		int i = 0;
		int j = 0;
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				ifs >> matrix[i][j];
			}
		}
		transposition(rows, cols, matrix);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
