#include <iostream>
#include <fstream>
using namespace std;

void print_primenum(int l, int r){
	if (l < 2) l = 2;
    if (l > r) {
		cout << endl;
		return;
	}
	int *arr = new int[r -l];
	int idx = 0;
	bool first_flag = true;
	while (l < r)
	{
		bool flag = true;
		for (int i = 2; i <= l/2; i++){
			if (l % i == 0){
				flag = false;
			}
		}
		if (flag){
			arr[idx] = l;
			idx++;
		}			
		l++;
	}
	if (idx > 0){
		for (int i = 0; i < idx - 1; i++)
			cout << arr[i] << " ";	
		cout << arr[idx - 1];
	}
	cout << endl;
	delete[] arr;
}

int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	int l, r;
	try
	{
		ifs >> l >> r;
        print_primenum(l , r);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}