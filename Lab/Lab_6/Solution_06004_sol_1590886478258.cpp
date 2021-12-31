#include <iostream>
#include <fstream>
using namespace std;
int findMax(int *vals, int numEls) {
	int j, max = *vals;
    for (j = 1; j < numEls; j++)
      if (max < *(vals + j))
          max = *(vals + j);
    return max;
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int size;
	ifs >> size;
	ifs.ignore(1, '\n');
    int i = 0;
	int *a = new int[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		cout << findMax(a, size) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}