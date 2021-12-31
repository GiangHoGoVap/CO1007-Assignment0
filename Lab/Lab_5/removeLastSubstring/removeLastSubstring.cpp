#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MAX_LEN 200

void removeLastSubString(char *str, char *sub)
{
//TODO
	char* ptr = str;
	while (strstr(ptr,sub)){
		ptr = strstr(ptr, sub);
		ptr = ptr + strlen(sub);
	}
	char* ptr1 = str+strlen(str)-strlen(ptr)-strlen(sub);
	char* ptr2 = str+strlen(str)-strlen(ptr);
	if (ptr != str) memmove(ptr1, ptr2, strlen(str));
}

int main(int narg, char **argv)
{
  ifstream ifs;
  ifs.open(argv[1]);

  char str1[MAX_LEN];
  char str2[MAX_LEN];

  ifs.get(str1, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');
  ifs.get(str2, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');

  removeLastSubString(str1, str2);
  cout << str1 << endl;
  ifs.close();
  return 0;
}
