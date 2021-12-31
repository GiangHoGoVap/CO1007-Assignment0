#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

//ifstream ifs;

int main(int narg, char **argv)
{
  //ifs.open(argv[1]);

  char str1[100];
  char str2[100];

  cin.get(str1, 100, '\n');
  cin.ignore(100, '\n');
  cin.get(str2, 100, '\n');
  cin.ignore(100, '\n');

//TODO
	int m = strlen(str1);
	int n = strlen(str2);
	int i;
	int j = 0;
	for (i=0; i<m && j<n;i++){
		if (str1[i] == str2[j]){
			j++;
		}
	}
	
	if (j==n){
		for (;i<=m ;i++){
			cout << str1[i];
		}
	} 
	else cout << "Not found";
	cout << "\n";
	
  //ifs.close();
  return 0;
}
