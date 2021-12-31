#include <iostream>
using namespace std;
int main(){
	int n;
	double a[n];
	cout << "Input the size of n: " ;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	float sum = 0;
	float average = 0;
	for (int j=0; j<n; j++){
		sum += a[j];
	}
	average = sum/n;
	cout << average;
	cout << "\n" ;
	return 0;
}
