#include <iostream>
#include <fstream>
using namespace std;
int linearSearch(int *a, int key, int sizeofArray)
{
    //TODO
    if (sizeofArray <= 0) return -1;
    if (key==a[sizeofArray-1]) return (sizeofArray-1);
    else return linearSearch(a, key, --sizeofArray);
}

// you should remove element in array
// function return array
int* removeElement(int *a, int &n, int position){
    //TODO
    if (position>n){
    	n--;
    	return a;
	} 
    else a[position] = a[position+1];
	return removeElement(a,n,position+1);
}
 

int main(int narg, char** argv)
{
	int N, M, position;
	cout << "Enter the size: " << endl;
	cin >> N;
	cout << "Enter the number you want to search: " << endl;
	cin >> M;
	cout << "Enter the position you want: " << endl;
	cin >> position;
    int i = 0;
	int *a = new int[N];
	for (int i=0; i<N; i++){
		cout << "Enter the [" << i << "]: " << endl;
		cin >> a[i];
	}
	cout << linearSearch(a, M, N) << endl;
	int* newA = removeElement(a, N, position);
	for(int i = 0; i < N; i++) {
		cout << newA[i] << " ";
	}
	cout << endl;
	
	return 0;
}
