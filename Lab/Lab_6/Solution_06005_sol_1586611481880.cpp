#include <iostream>
#include <fstream>
using namespace std;
// implement calculate factorial in here
long  calculateFactorial(int n)
{
    long result = 1;
     for (int i = 1; i <= n; i++)
     {
         result = result * i;
     }
  	return result;
}

int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	try
	{
		ifs >> N;
		long result;
		// call function calculateFactorial in here and assign value to the variable result
		result = calculateFactorial(N);
		cout << result << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}