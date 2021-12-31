/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07002_sol.cpp
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
    //BeginTodo
    bool operator==(int _value);
	Integer(int _value);
	Integer operator=(int _value);
	bool operator<(Integer obj);
	Integer operator+(int _value);
	operator int();
	bool operator>(Integer obj);
    //EndTodo
};

/**
 * Student implement Integer's methods here
*/

//BeginTodo
bool Integer::operator==(int _value) { return this->value == _value; }
Integer::Integer(int _value) { this->value = _value; }
Integer Integer::operator=(int _value) { this->value = _value; return *this; }
bool Integer::operator<(Integer obj) { return this->value < obj.value; }
Integer Integer::operator+(int _value) { return Integer(this->value + _value); }
Integer::operator int() { return this->value; }
bool Integer::operator>(Integer obj) { return this->value > obj.value; };
//EndTodo

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
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
