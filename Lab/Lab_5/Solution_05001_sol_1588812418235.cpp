#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MAX_LEN 200

void removeLastSubString(char *str, char *sub)
{
  int len = strlen(sub);
  if (len > 0)
  {
    char *p = str;
    char *lastPos = NULL;
    while ((p = strstr(p, sub)) != NULL)
    {
      lastPos = p;
      p += len;
    }
    if (lastPos != NULL)
    {
      memmove(lastPos, lastPos + len, strlen(lastPos + len) + 1);
    }
  }
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