#include <iostream>
#include <fstream>
using namespace std;
int findMax(int *vals, int numEls) {
	// TODO
    int max=vals[0];
	for (int i=1; i<numEls; i++){
		if (max < vals[i]) max=vals[i];
	}
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