#include <iostream>
#include <fstream>
using namespace std;
bool uniqueElement(int size, int *a, int i)
{
	if (i == size - 1) return true;
	for (int j = i + 1; j < size; j++ ) {
		if (a[i] == a[j]) return false;
	}
	return uniqueElement(size, a, i + 1);
}

int main(int narg, char** argv)
{
	
	ifstream ifs;
	ifs.open(argv[1]);

	int size;
	ifs >> size;
    int i = 0;
	int *a = new int[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		cout << uniqueElement(size, a, 0) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
