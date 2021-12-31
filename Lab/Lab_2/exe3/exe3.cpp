#include <iostream>
#include <fstream>
using namespace std;
void averageValue(int n, double *a) {
	// TODO
    float sum = 0;
	float average = 0;
	for (int j=0; j<n; j++){
		sum += a[j];
	}
	average = sum/n;
	cout << average;
	cout << "\n" ;
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
		averageValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
