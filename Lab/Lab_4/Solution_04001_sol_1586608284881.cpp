#include <iostream>
#include <fstream>
using namespace std;
int permutation(int n, int m) {
	if (m == 0 || m == n) return 1;
	return permutation(n - 1, m) + permutation(n - 1, m - 1);
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	int M;
	try
	{
		ifs >> N;
		ifs >> M;
		cout << permutation(N, M) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
