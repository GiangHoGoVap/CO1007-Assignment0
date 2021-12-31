/*****Version 1.1***********/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(const char* filename, int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	ifstream in;
	in.open(filename);
	
	if (!in.good()) return 0;

	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;

	in.close();

	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;

	return 1;

}

// TODO: Your code goes here
bool isPrimeNumber(int n){
	for (int i = 2; i <= n/2 ; ++i){
		if (n % i == 0) return false;
	}
	return true;
}

void display(float fOut)
// display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}


int main(int argc, char** argv)
{
	if (argc < 2) return 1;

	const char* filename = argv[1];
	cout << filename << endl;

	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(filename, baseHP1, baseHP2, wp1, wp2, ground);
	
	// TODO: Your code goes here
	float realHP1, realHP2;
	
	//Check wp[i] = 0
	if (wp1 == 0) realHP1 = round((baseHP1/10)*100)/100;
	if (wp2 == 0) realHP2 = round((baseHP2/10)*100)/100;
	
	//Check wp[i] = 1
	if (wp1 == 1) realHP1 = baseHP1;
	if (wp2 == 1) realHP2 = baseHP2;
	
	//Check baseHP = ground, using realHP in formula because it depends on wp = 0 or wp = 1
	if(baseHP1 == ground) realHP1 = (realHP1 * 1.1 > 999)? 999 : realHP1 * 1.1;
	if(baseHP2 == ground) realHP2 = (realHP2 * 1.1 > 999)? 999 : realHP2 * 1.1;
	
	//Check wp[i] = 2
	if (wp1 == 2){
		if (baseHP1 == ground){
			realHP1 = (baseHP1 * 1.1 > 999)? 999 : baseHP1 * 1.1;
		}
		else realHP1 = baseHP1;
	}
	if (wp2 == 2){
		if (baseHP2 == ground){
			realHP2 = (baseHP2 * 1.1 > 999)? 999 : baseHP2 * 1.1;
		}
		else realHP2 = baseHP2;
	}
	
	//Check wp[i] = 3
	if (wp1 == 3){
		if (baseHP1 == ground){
			realHP1 = (baseHP1 * 1.1 > 999)? 999 : baseHP1 * 1.1 * 2;
		}
		else realHP1 = (baseHP1 * 2 > 999)? 999 : baseHP1 * 2; //Check in case baseHP != ground so back to wp = 1
		if (wp2 == 2) realHP1 = baseHP1 * 2; //Check the special note
	}
	if (wp2 == 3){
		if (baseHP2 == ground){
			realHP2 = (baseHP2 * 1.1 > 999)? 999 : baseHP2 * 1.1;
		}
		else realHP2 = baseHP2;
	}
	
	//Calculate the probability
	fOut = (realHP1 - realHP2 + 999)/2000;
	
	//Check wp = 2 and realHP lower than opponent
	if ((wp1 == 2 && realHP1 < realHP2)||(wp2 == 2 && realHP2 < realHP1)) fOut = 0.5;
	
	//King Arthur
	if (baseHP1 == 999) fOut = 1;
	
	//Cerdic
	if (baseHP2 == 888){
		if (baseHP1 == 999) fOut = 1;
		else fOut = 0;
	}
	
	//Prime number is Paladin
	if (isPrimeNumber(baseHP1)){
		if (baseHP2 == 888) fOut = 0;
		else if (isPrimeNumber(baseHP2) && baseHP2 > baseHP1) fOut = 0.01;
		else if (isPrimeNumber(baseHP2) && baseHP2 == baseHP1) fOut = 0.5;
		else fOut = 0.99;
	}
	if (isPrimeNumber(baseHP2)){
		if (baseHP1 == 999) fOut = 1;
		else if (isPrimeNumber(baseHP1) && baseHP1 > baseHP2) fOut = 0.99;
		else if (isPrimeNumber(baseHP1) && baseHP2 == baseHP1) fOut = 0.5;
		else fOut = 0.01;
	}

	display(fOut);

	return 0;
}
