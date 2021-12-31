/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07003_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Tue Apr 23 10:19:58 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07003_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//------------------------------------------------------------------------
/**
* Champion class definition 
*/
class Champion {
	int id;
	int health;
	int damage;
	static int numberOfAliveChampions;	// Think: Why static? What is a static member?
	/* What are the differences between a static member and the others? */
public:
	Champion(int _id, int _health, int _damage);
	~Champion();
	bool attack(Champion& _victim);
	int getHeath();
	static int getNumberOfAliveChampions();	// Why static? What is a static method?
	/* What are the differences between a static method and the others? */
};


/**
* Champion class implementation
*/

/* The constructor */
Champion::Champion(int _id, int _health, int _damage) {
	// Hint: set the corresponding passed values to id, health, and damage
	// Hint: We have a static variable for alive champion counting!
    //TODO
	id = _id;
	health = _health;
	damage = _damage;
	numberOfAliveChampions++;
}

/* The destructor */
Champion::~Champion() {
	// Think: What must be done when the the object is destroyed?
	// Hint: We have a static variable for alive champion counting!
    //TODO
	numberOfAliveChampions--;
}

/* This champion attack another champion, the victim will lose an amount of health
equal to the attacker damage, return true if the victim dies after being attacked */
bool Champion::attack(Champion& _victim) {
    //TODO
	_victim.health = _victim.health - this->damage;
	if (_victim.health <= 0) return true;
	return false;
}

/* The getter for instance member: this->health */
int Champion::getHeath() {
    //TODO
	return this->health;
}

/* The getter for the class member: Champion::numberOfAliveChampions */
int Champion::getNumberOfAliveChampions() {	// Why static? What is a static method?
    //TODO
	return numberOfAliveChampions;
}
// Think: What are the differences between the two getter above?

// Think: What is the following line for?
int Champion::numberOfAliveChampions = 0;

/**
* Some function for combating (of course, champion have to combat :v)
*/

/* For each event, if event is true then the champion A attack the champion B and vise versa.
Return 1 if the champion A killed the champion B, return -1 if the champion B killed the champion A,
or return 0 if no one dies after the fight. Please note that, to mark that a champion is killed,
you have to delete that champion object and set the corresponding pionter to NULL*/
int fight(Champion*& a, Champion*& b, bool* eventList, int numberOfEvent) {
	/*Please note that, to mark that a champion is killed,
	you have to delete that champion object and set the corresponding pionter to NULL */
    //TODO
    for (int i=0; i<numberOfEvent; i++){
    	if (eventList[i] == true){
    		if (a->attack(*b)){
    			delete b;
    			b = NULL;
				return 1;
			}
		}
		
		else{
			if (b->attack(*a)){
    			delete a;
    			a = NULL;
				return -1;
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------

struct Match {
	int indexOfA;
	int indexOfB;
	int numberOfEvents;
	bool* eventList;
};

/* There are many matches, in each match, the two champion will fight with each other */
void combat(Champion** championList, int numberOfChampions, Match* matchList, int numberOfMatches) {
	for (int i = 0; i < numberOfMatches; i++) {
		if (championList[matchList[i].indexOfA] != NULL && championList[matchList[i].indexOfB] != NULL)
			fight(championList[matchList[i].indexOfA], championList[matchList[i].indexOfB], matchList[i].eventList, matchList[i].numberOfEvents);
	}
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
		int numberOfChampions;
		fileIn >> numberOfChampions;
		Champion** champList = new Champion*[numberOfChampions];
		int id, health, damage;
		for (int i = 0; i < numberOfChampions; i++) {
			fileIn >> id >> health >> damage;
			champList[i] = new Champion(id, health, damage);
		}
		int numberOfMatches;
		fileIn >> numberOfMatches;
		Match* matchList = new Match[numberOfMatches];
		for (int i = 0; i < numberOfMatches; i++) {
			fileIn >> matchList[i].indexOfA >> matchList[i].indexOfB;
			fileIn >> matchList[i].numberOfEvents;
			matchList[i].eventList = new bool[matchList[i].numberOfEvents];
			for (int j = 0; j < matchList[i].numberOfEvents; j++) fileIn >> matchList[i].eventList[j];
		}
		combat(champList, numberOfChampions, matchList, numberOfMatches);
		cout << Champion::getNumberOfAliveChampions();
        fileIn.close();
		for (int i = 0; i < numberOfChampions; i++) delete champList[i];
		delete[] champList;
		for (int i = 0; i < numberOfMatches; i++) delete[] matchList[i].eventList;
		delete[] matchList;
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

