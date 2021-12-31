#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool ArmstrongNum(int n){
    //TODO
    int Sum = 0;
	int i = 0;
	int p = n;
	int q = n;
	while (n > 0){
		n = n/10;
		i += 1;
	}
	
	for (int j = 1; j <= i; j++){
		int r = p%10;
		p = p/10;
		Sum += pow(r,i);
	}
		
	if (Sum == q) return true;
	else return false;
}

int main(int arg, char** argv){
    //ifstream ifs;
	//ifs.open(argv[1]);
	int N;
	try
	{
		//ifs >> N;
		cout << "Input the number: " << endl;
		cin >> N;
        printf("%s\n", ArmstrongNum(N)?"true":"false");
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	//ifs.close();
	return 0;
}
