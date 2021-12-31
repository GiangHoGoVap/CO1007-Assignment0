#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
bool palindrome(char strg[], int j)
{
    //TODO
    int n = strlen(strg) - j - 1;
    if (j==n) return true;
    if (strg[j]!=strg[n]) return false;
    return palindrome(strg,j+1);
}


int main(int narg, char** argv)
{
	char strg[20];
	cout << "Enter a string: " << endl;
	gets(strg);
	cout << palindrome(strg,0) << endl;
	return 0;
}
