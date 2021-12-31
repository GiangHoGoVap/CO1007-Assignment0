#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int **a)
{
//TODO
	bool numberZero = false;
	for (int i=0; i<10; i++){
		numberZero = false;
		for (int j=0; j<10; j++){
			if (numberZero) a[i][j] = 0;
			else{
				ifs >> a[i][j];
				if (a[i][j] == 0) numberZero = true;
			}
		}
	}
}

void printArray(int **a)
{
//TODO
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if (j == 0) cout << a[i][j];
            else cout << " " << a[i][j];
            if(j == 10 - 1) cout << "\n";
		}
	}
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int **arr;
  arr = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    arr[i] = new int[10];
  }

  readArray(arr);
  printArray(arr);

  for (int i = 0; i < 10; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

  ifs.close();
  return 0;
}
