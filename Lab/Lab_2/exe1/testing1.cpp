#include <iostream>
using namespace std;

void Fibonacci(int n){
	int fib[n+2], i;
	fib[0] = 0;
	fib[1] = 1;
	for (i=2; i<=n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	cout << fib[n];
}

int main(){
	int n;
	cin >> n;
	Fibonacci(n);
	return 0;
}
