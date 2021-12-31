#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
  char min[100];
  char mid[100];
  char max[100];

  if (strcmp(str1, str2) <= 0 && strcmp(str1, str3) <= 0)
  {
    strcpy(min, str1); //str1 is min
    if (strcmp(str2, str3) <= 0)
    {
      strcpy(mid, str2);
      strcpy(max, str3);
    }
    else
    {
      strcpy(mid, str3);
      strcpy(max, str2);
    }
  }
  if (strcmp(str2, str1) <= 0 && strcmp(str2, str3) <= 0)
  {
    strcpy(min, str2); //str2 is min
    if (strcmp(str1, str3) <= 0)
    {
      strcpy(mid, str1);
      strcpy(max, str3);
    }
    else
    {
      strcpy(mid, str3);
      strcpy(max, str1);
    }
  }
  if (strcmp(str3, str1) <= 0 && strcmp(str3, str2) <= 0)
  {
    strcpy(min, str3); //str3 is min
    if (strcmp(str1, str2) <= 0)
    {
      strcpy(mid, str1);
      strcpy(max, str2);
    }
    else
    {
      strcpy(mid, str2);
      strcpy(max, str1);
    }
  }

  cout << min << endl
       << mid << endl
       << max << endl;
}

int main(int narg, char **argv)
{
  ifstream ifs;
  ifs.open(argv[1]);

  char str1[100];
  char str2[100];
  char str3[100];

  ifs.get(str1, 100, '\n');
  ifs.ignore(100, '\n');
  ifs.get(str2, 100, '\n');
  ifs.ignore(100, '\n');
  ifs.get(str3, 100, '\n');
  ifs.ignore(100, '\n');

  printOrder(str1, str2, str3);

  ifs.close();
  return 0;
}