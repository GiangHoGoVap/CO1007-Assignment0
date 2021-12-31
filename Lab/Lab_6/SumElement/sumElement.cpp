#include <iostream>
#include <fstream>
using namespace std;
int sum(int array[], int numEls)
{
    // TODO
	int sum=0;
	for (int i=0; i<numEls; i++){
    	sum = sum+array[i];
	}
	return sum;
}

void sum2(int * array, int numEls, int &result)
{
    // TODO
	for (int i=0; i<numEls; i++){
    	result = result + array[i];
	}
}

int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int size;
	int t;
	ifs >> size;
	ifs >> t;
	ifs.ignore(1, '\n');
    int i = 0;
	int *a = new int[size];
	try {
		while (ifs >> a[i])
		{
			i++;
		}
		if (t == 1 || t == 3) {
			cout << sum(a, size) << endl;
		}
		if (t == 2 || t == 3) {
			int result = 0;
			sum2(a, size, result);
			cout << result << endl;
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
