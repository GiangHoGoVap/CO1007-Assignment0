#include <iostream>
#include <fstream>
using namespace std;
int cube(int a)
{
        a = a*a*a;
        return a;
}

void cube2(int &a)
{
        a = a*a*a;
}

void cube3(int *a)
{
        *a = (*a) * (*a) * (*a);
}

int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	int i;
	try
	{
		ifs >> N;
		ifs >> i;
		if (i == 1 || i == 4) {
			cout << cube(N) << endl;
		}
		if (i == 2 || i == 4) {
			int N2 = N;
			cube2(N2);
			cout << N2 << endl;
		}
		if (i == 3 || i == 4) {
			int N3 = N;
			cube3(&N3);
			cout << N3 << endl;
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
