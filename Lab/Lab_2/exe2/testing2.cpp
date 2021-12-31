#include <iostream>
using namespace std;

int main(){
	int N;
	double a[N];
	
	cout << "Input the size of array: " << endl;
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> a[i];
	}
	
	float max = 0;
	for(int j=0; j<N; j++){
		if (max < a[j]) max = a[j];
	}
	cout << max;
	
	cout << "\n";
	
}
