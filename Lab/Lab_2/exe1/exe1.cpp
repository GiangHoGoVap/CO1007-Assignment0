#include <iostream>
#include <fstream>
using namespace std;
void Fibonacci(int n) {
	// TODO
	int fib[n+2], i;
	fib[0] = 0;
	fib[1] = 1;
	for (i=2; i<=n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	cout << fib[n];
	cout << "\n";
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
