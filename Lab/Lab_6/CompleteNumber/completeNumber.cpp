#include <iostream>
#include <fstream>
using namespace std;
bool completeNum(int N)
{
	// TODO
    int sum = 0;
	for (int i=1; i<=N; i++){
		if (N % i == 0) sum+=i;
	}
	if (sum == 2*N) return true;
	else return false;
}

int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	try
	{
		while (ifs >> N) {
			cout << completeNum(N) << endl;
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
