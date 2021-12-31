#include <iostream>
#include <fstream>
using namespace std;

void print_primenum(int l, int r){
    //TODO
    int i, j, flag;
    bool firstTime = true;
    
    for(i = l; i < r; i++){
    	if (i == 1||i == 0) continue;
    	flag = 1;
    	for (j = 2; j <= i/2; j++){
    		if (i % j == 0){
    			flag = 0;
    			break;
			}
		}
		if (flag == 1){
			if(firstTime){
				cout << i;
				firstTime = false;
			}
			else cout << " " << i;
		}
	}
	cout << "\n";
}

int main(int arg, char** argv){
    //ifstream ifs;
	//ifs.open(argv[1]);
	int l, r;
	try
	{
		cout << "Input l and r: " << endl;
		cin >> l >> r;
        print_primenum(l , r);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	//ifs.close();
	return 0;
}
