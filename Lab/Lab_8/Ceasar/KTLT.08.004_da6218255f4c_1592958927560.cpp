/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07004_ini.cpp
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
    // TODO
textBuffer = NULL;

}

/* The copy constructor */
CaesarMessage::CaesarMessage(CaesarMessage& obj) {
    // TODO
textBuffer = new char[strlen(obj.textBuffer)+1];
strcpy(textBuffer, obj.textBuffer);

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
    // TODO
int length = 0;
    int newLength = 0;
    char tmp;
    int vl;
    while(_message[length] != '\0')
    {
    	if (tolower(_message[length]) <= int('z') && tolower(_message[length]) >= int('a')) newLength++;
    	length++;
	}
	
  //cout << "Allocate textBuffer 3" << endl;
	textBuffer = new char[newLength+1];
	
	for(int i = 0, j = 0; i < length; i++)
	{
		//tmp = char(tolower(_message[i]));
		vl = tolower(_message[i]);
		if (vl <= int('z') && vl >= int('a'))
		{
			//tmp = char(int(tmp) + _shift);
			vl += _shift;
			while (vl > int('z'))
			{
				vl -= 26;
			}
			tmp = char(vl);
			textBuffer[j] = tmp;
			j++;
		}
	}
	textBuffer[newLength] = '\0';

}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char*& _textContainer) {
    // TODO
int length = strlen(textBuffer);
    char tmp;
    int vl;
  
	_textContainer = new char[length+1];
	
	for (int i = 0; i < length; i++)
	{
		//tmp = char((int(textBuffer[i]) - _shiftKey) % 26);
		vl = int(textBuffer[i]);
		vl -= _shiftKey;
		while (vl < int('a'))
		{
			vl += 26;
		}
		tmp = char(vl);
		_textContainer[i] = tmp;
	}
	
	_textContainer[length] = '\0';


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

