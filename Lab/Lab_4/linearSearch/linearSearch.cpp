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
	ifstream ifs;
	ifs.open(argv[1]);

	int N, M, position;
	ifs >> N;
	ifs >> M;
	ifs >> position;
    int i = 0;
	int *a = new int[N];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		cout << linearSearch(a, M, N) << endl;
		int* newA = removeElement(a, N, position);
		for(int i = 0; i < N; i++) {
			cout << newA[i] << " ";
		}
		cout << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
