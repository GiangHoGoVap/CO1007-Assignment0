#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

const int MAX = 100;
//ifstream ifs;

struct student
{
	char name[20];
	long int rollno;
	char sex;
	float height;
	float weight;
};

int main(int narg, char **argv)
{
	//ifs.open(argv[1]);

	student cls[MAX];
	int n;

	try
	{
    	cin >> n;
    	if (n <= 0)
    	{
      		throw n;
    	}
    	for (int i = 0; i < n; i++)
    	{
      		cin >> cls[i].name;
      		cin >> cls[i].rollno;
      		cin >> cls[i].sex;
      		cin >> cls[i].height;
      		cin >> cls[i].weight;
    	}
    	cout << left << setw(22) << "Name"
       		 << left << setw(8) << "Rollno"
        	 << left << setw(8) << "Sex"
        	 << left << setw(8) << "Height"
        	 << left << setw(8) << "Weight" << endl;

		//TODO
		for (int i=0; i<n ; i++){
			cout << left << setw(22) << cls[i].name
			 	 << left << setw(8) << cls[i].rollno
			 	 << left << setw(8) << cls[i].sex
			 	 << left << setw(8) << cls[i].height 
			 	 << left << setw(8) << cls[i].weight << endl;
		}
		
		//Calculate Average height, Average weight
		float sumHeight = 0;
		float sumWeight = 0;
		for (int i=0; i<n; i++){
			sumHeight = sumHeight + cls[i].height;
			sumWeight = sumWeight + cls[i].weight;
		}	
		cout << "Average height: " << sumHeight/n << endl;
		cout << "Average weight: " << sumWeight/n;
		cout << "\n";
  	}
	catch (int n)
  	{
    	cout << "Invalid n" << endl;
  	}

  	//ifs.close();
  	return 0;
}
