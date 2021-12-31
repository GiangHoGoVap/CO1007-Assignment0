#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int **a)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      ifs >> a[i][j];
      if (a[i][j] == 0)
      {
        for (int k = j + 1; k < 10; k++)
        {
          a[i][k] = 0;
        }
        break;
      }
    }
  }
}

void printArray(int **a)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cout << a[i][j];
      if (j != 9)
      {
        cout << " ";
      }
    }
    cout << endl;
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