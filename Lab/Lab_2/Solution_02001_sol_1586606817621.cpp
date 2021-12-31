#include <iostream>
#include <fstream>
using namespace std;
void Fibonacci(int n) {
	// initialized array
	int a [n];
	for (int index = 0; index <= n; index++) {
		if (index == 0) a[index] = 0;
		else if (index == 1) a[index] = 1;
		else a[index] = a[index - 1] + a[index - 2];
	}
	cout << a[n] << endl;
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int a;
	try
	{
		while (ifs >> a)
		{
			Fibonacci(a);
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
