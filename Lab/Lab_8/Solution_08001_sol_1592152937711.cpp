/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07001_sol.cpp
    @author CSE - HCMUT
    @version 1.0 Mon Apr 22 15:39:06 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
#define FILENAME "07001_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "vector"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
	// The constructor
	Integer(int _value);

	// The getter
	int getValue();

	//The setter
	void setValue(int _value);
};

/**
* Student implement Integer's methods here
*/
// BeginTodo
Integer::Integer(int _value = 0) { this->value = _value; }
int Integer::getValue() { return this->value; }
void Integer::setValue(int _value) { this->value = _value; }
// EndTodo

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include", "vector"};
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

void process(vector<Integer> integerVector) {
    int numberOfElements = integerVector.size();
    int temp;
    int count = 1;
    while (count != 0) {
        count = 0;
        for (int i = 0; i < numberOfElements - 1; i++) {
            if (integerVector[i].getValue() > integerVector[i + 1].getValue()) {
                count++;
                temp = integerVector[i].getValue();
                integerVector[i].setValue(integerVector[i+1].getValue());
                integerVector[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < numberOfElements; i++) {
        cout << integerVector[i].getValue();
        if (i < numberOfElements - 1) cout << " ";
    }
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
        vector<Integer> integerVector;
        int temp;
        while (!fileIn.eof()) {
            fileIn >> temp;
            integerVector.push_back(Integer(temp));
        }
        process(integerVector);
        fileIn.close();
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}
