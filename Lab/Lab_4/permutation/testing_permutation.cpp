#include <iostream>
#include <fstream>
using namespace std;
int permutation(int n, int m) {
	//TODO
	if (m==0 || n==m) return 1;
	else if (n>m) return permutation(n-1,m) + permutation(n-1,m-1);
}
int main(int narg, char** argv)
{
	//ifstream ifs;
	//ifs.open(argv[1]);
	int N;
	int M;
	try
	{
		cin >> N;
		cin >> M;
		cout << permutation(N, M) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	//ifs.close();
	return 0;
}
