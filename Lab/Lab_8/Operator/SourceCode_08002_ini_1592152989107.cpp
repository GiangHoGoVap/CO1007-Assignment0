/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07002_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Mon Apr 22 17:09:40 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07002_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
    Integer () {}
	// Methods prototypes only
    //TODO
    operator int const();
	Integer operator+(const int &b);
	bool operator>(const Integer &b);
	bool operator<(const Integer &b);
	bool operator==(const int &b);
	void operator=(const int &b);
	Integer (int value);
};

/**
 * Student implement Integer's methods here
*/

//TODO
Integer::operator int const(){
	return int(value);
}

Integer::Integer(int _value){
	value = _value;
}

Integer Integer::operator+(const int &b){
	Integer c;
	c.value = this->value + b;
	return c;
}

bool Integer::operator>(const Integer &b){
	if (this->value > b.value) return true;
	else return false;
}

bool Integer::operator<(const Integer &b){
	if (this->value < b.value) return true;
	else return false;
}

bool Integer::operator==(const int &b){
	if (this->value == b) return true;
	else return false;
}

void Integer::operator=(const int &b){
	this->value = b;
}

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(2);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail()) ifs.open(FILENAME, ios::in);
    if (ifs.fail()) return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char* todoSegment = strstr(fileContent ,"// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char*);
    for (int i = 0; i < numberOfForbiddenKeyword; i++) { if (strstr(todoSegment, forbiddenKeyword[i])) return false; }
    delete[] fileContent;
    return true;
}

int main(int argc, char* argv[]) {
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2) return 0;
    ifstream fileIn;
    try {
        fileIn.open(argv[1]);
        if (fileIn.fail()) throw "Failed to open file.";
        int numberOfElements;
        fileIn >> numberOfElements;
        Integer* arr = new Integer[numberOfElements];
        int temp;
        for (int i = 0; i < numberOfElements; i++) {
            fileIn >> temp;
            arr[i] = temp;
        }
        cout << max(arr, numberOfElements);
        delete[] arr;
        fileIn.close();
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

