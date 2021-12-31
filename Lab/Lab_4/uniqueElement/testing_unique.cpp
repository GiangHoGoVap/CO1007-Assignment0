#include <iostream>
#include <fstream>
using namespace std;
bool uniqueElement(int size, int *a, int i)
{
	//TODO
	int n=i/size;
	if (n == size - 1) return true;
	else
	{
		if (n != i%size && a[n] == a[i%size]) return false;
		return uniqueElement(size, a, i+1);
	}
}

int main(int narg, char** argv)
{
	
	int size;
	int *a = new int[size];
	cout << "enter the size: " << endl;
	cin >> size;
	for (int i=0; i<size; i++){
		cin >> a[i];
	}
	cout << uniqueElement(size, a, 0);
	return 0;
}
