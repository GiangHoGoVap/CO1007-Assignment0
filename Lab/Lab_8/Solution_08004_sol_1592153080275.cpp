/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07004_sol.cpp
    @author CSE - HCMUT
    @version 1.0 Tue Apr 23 17:52:55 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//---------------------------------------------------------------------------
/**
* CaesarMessage class definition
*/
class CaesarMessage {
	char* textBuffer;
public:
	CaesarMessage();
	CaesarMessage(CaesarMessage& obj);
	~CaesarMessage();
	void encode(const char* _message, int _shift);
	void decode(int _shiftKey, char*& _textContainer);
};

/**
* CaesarMessage class implementation
*/

/* The default constructor */
CaesarMessage::CaesarMessage() {
	//BeginTodo
	this->textBuffer = NULL;
	//EndTodo
}

/* The copy constructor */
CaesarMessage::CaesarMessage(CaesarMessage& obj) {
	//BeginTodo
	this->textBuffer = new char[strlen(obj.textBuffer) + 1];
	strcpy(this->textBuffer, obj.textBuffer);
	//EndTodo
}

/* The destructor */
CaesarMessage::~CaesarMessage() {
	/* You have to tidy the dynamic memory, right?
	But, wait! What will happen if the textBuffer has been deleted already?
	Can that problem happen? When, why? And what is the solution? */
	delete[] this->textBuffer;
}

/* Encode the input message and then store the result in the textBuffer */
void CaesarMessage::encode(const char* _message, int _shift) {
	/* Guide: Lower case all the characters and then do the shifting.
	Just encode the alphabet, ignore any others */
	//BeginTodo
	int len = strlen(_message);
	char* message = new char[len + 1];
	strcpy(message, _message);
	int count = 1;
	for (int i = 0; i < len; i++) {
		message[i] = tolower(message[i]);
		if (isalpha(message[i])) {
			message[i] = (message[i] - 97 + _shift) % 26 + 97;
			count++;
		}
	}
	this->textBuffer = new char[count];
	int idx = 0;
	for (int i = 0; i < len; i++) if (isalpha(message[i])) this->textBuffer[idx++] = message[i];
	this->textBuffer[idx] = '\0';
	delete[] message;
	//EndTodo
}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char*& _textContainer) {
	//BeginTodo
	_shiftKey = _shiftKey % 26;
	int shift = 26 - _shiftKey;
	int len = strlen(this->textBuffer);
	_textContainer = new char[len + 1];
	for (int i = 0; i < len; i++) {
		_textContainer[i] = (this->textBuffer[i] - 97 + shift) % 26 + 97;
	}
	_textContainer[len] = '\0';
	//EndTodo
}

/* Notice this function */
void process(CaesarMessage msg, int shiftKey, char*& container) {
    msg.decode(shiftKey, container);
}

//---------------------------------------------------------------------------
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
        int shift;
        fileIn >> shift;
        string line;
        string inputString;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            if (line.length() > 0) if (line[line.length() - 1] == 13) line.pop_back();
            inputString += line;
        }
        char* plainText = new char[strlen(inputString.c_str()) + 1];
        strcpy(plainText, inputString.c_str());
        char* decodedText;
        {
            CaesarMessage msg;
            msg.encode(plainText, shift);
            process(msg, shift, decodedText);
        }
        cout << decodedText;
        delete[] decodedText;
        delete[] plainText;
        fileIn.close();
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}
