#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
//TODO
	int i,j;
	char STR[3][100];
	strcpy(STR[0],str1);
	strcpy(STR[1],str2);
	strcpy(STR[2],str3);
 
	char t[100];
	
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
         	if(strcmp(STR[i],STR[j])>0){
            	strcpy(t,STR[i]);
            	strcpy(STR[i],STR[j]);
            	strcpy(STR[j],t);
        	}
      	}
	}
	
	for (i=0; i<3; i++){
		cout << STR[i] << endl;
	}
    
}

int main(int narg, char **argv)
{
  //ifstream ifs;
  //ifs.open(argv[1]);

  char str1[100];
  char str2[100];
  char str3[100];

  cin.get(str1, 100, '\n');
  cin.ignore(100, '\n');
  cin.get(str2, 100, '\n');
  cin.ignore(100, '\n');
  cin.get(str3, 100, '\n');
  cin.ignore(100, '\n');

  printOrder(str1, str2, str3);

  //ifs.close();
  return 0;
}
