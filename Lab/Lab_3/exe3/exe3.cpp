#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream ifs;

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  char str1[100];
  char str2[100];

  ifs.get(str1, 100, '\n');
  ifs.ignore(100, '\n');
  ifs.get(str2, 100, '\n');
  ifs.ignore(100, '\n');

// TODO
    char *ret1;
	int n = strlen(str2);
	ret1 = strstr(str1, str2);
	if (ret1 == NULL) cout << "Not found" << endl;
	else{
		string ret2(ret1);
		int pos = ret2.find(str2);
		string sub = ret2.substr(pos+n);
		cout << sub << endl;
	}

  ifs.close();
  return 0;
}