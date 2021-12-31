#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
bool palindrome(char strg[], int j)
{
    int len = strlen(strg);
	if (j == len/2) return true;
    if (j < len && strg[j] != strg[len - 1 - j]) return false;
    return (palindrome(strg, j + 1));
}


int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	char strg[100];
	try
	{	
		while (ifs.getline(strg, 100, '\n')) {
			cout << strg << " " << palindrome(strg, 0) << endl;
			if (strg[0] == '*') break;
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
