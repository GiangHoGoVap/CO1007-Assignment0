#include <iostream>
using namespace std;
int main()
{
	int n;
	float* ptr = new float[n];
	
 	cout << "Enter the number of students: ";
 	cin >> n;
 	cout << "Enter the GPA of students." << endl;
 	
 	for (int i = 0; i < n; i++)
 	{
 		cout << "Student [" << i + 1 << "]: ";
 		cin >> *(ptr + i);
 	}
 	
 	cout << "Display: " << endl;
 	
 	for (int i = 0; i < n; i++) {
 		cout << "Student [" << i + 1 << "]: " << *(ptr + i) << endl;
 	}
 	
 	delete [] ptr;
	return 0;

}
