#include <iostream>
#include <fstream>
using namespace std;
bool completeNum(int N)
{
	int Sum = 0;
    for (int i = 1; i < N; i++) {
        if (N % i == 0)
			Sum += i;
	}
    if (Sum == N)
        return true;
    return false;
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
