#include <iostream>
#include <math.h>
using namespace std;
float calculateSD(float arr[])
{
	float sum = 0;
	float mean;
	float SD = 0;
	
	for (int i=0; i<10; i++)
	{
		sum = sum + arr[i];
	}
	
	mean = sum/10;
	
	for (int i=0; i<10; i++)
	{
		SD = SD + pow(arr[i] - mean, 2);
	}
	return sqrt(SD/10);
}
int main(){
	
    float arr[10];
    
    for (int i=0; i<10; i++)
	{
    	cin >> arr[i];
	}
	
	cout << calculateSD(arr);
	return 0;

}
