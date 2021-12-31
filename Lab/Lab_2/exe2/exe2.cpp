#include <iostream>
#include <fstream>
using namespace std;
void maxValue(int n, double *a) {
	// TODO
    float max = 0;
	for(int j=0; j<n; j++){
		if (max < a[j]) max = a[j];
	}
	cout << max;
	cout << "\n";
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int size;
	ifs >> size;
	ifs.ignore(1, '\n');
    int i = 0;
	double *a = new double[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		maxValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
