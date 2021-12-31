#include <iostream>
#include <fstream>
using namespace std;
// implement calculate factorial in here
// TODO
int calculateFactorial(int N){
	int product = 1;
	for (int i=1; i<=N; i++){
		product = product*i;
	}
	if (N==0) return product;
	return product;
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
		// TODO
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