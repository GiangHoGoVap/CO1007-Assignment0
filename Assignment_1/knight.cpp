#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

const int SURRENDER = 0;
const int MADBEAR = 1;
const int BANDIT = 2;
const int LORDLUPIN = 3;
const int ELF = 4;
const int TROLL = 5;
const int SHAMAN = 6;
const int VAJSH = 7;
const int EXCALIBUR = 8;
const int MYTHRIL = 9;
const int EXCALIPOOR = 10;
const int MUSHMARIO = 11;
const int MUSHFIB = 12;
const int MUSHGHOST = 13;
const int MUSHKNIGHT = 14;
const int REMEDY = 15;
const int MAIDENKISS = 16;
const int PHOENIXDOWN = 17;
const int MERLIN = 18;
const int ABYSS = 19;
const int GUINEVERE = 20;
const int LIGHTWING = 21;
const int ODIN = 22;
const int DRAGONSWORD = 23;
const int BOWSER = 99;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
	int HP;
	int level;
	int remedy;
	int maidenkiss;
	int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = filename;
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1){
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
    // cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len){
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0'){
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
    delete[] str;
	}
	fclose(f);
	return 1;
}

void display(int* nOut)
{
  if (nOut)
    cout << *nOut;
  else
    cout << "Error!";
}

bool isPrimeNumber(int n){
	for (int i = 2; i <= n/2 ; ++i){
		if (n % i == 0) return false;
	}
	return true;
}

bool isDragonKnight(int m){
	for (int a = m - 2; a>0; a--){
		int a1 = m - a;
		for (int b = 1; b < a1; b++){
			int c = m - a - b;
			if (a*a == b*b + c*c){
				//cout << "This is Dragon Knight" << endl;
				return true;
			} 
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	
	const char *filename;
    if (argc < 2) filename="input.txt"; //return 1;
    else /*const char**/ filename = argv[1];
	
	struct knight theKnight;
	int nEvent; //number of events
	int* arrEvent = new int[EVENT_SIZE]; // array of events
	int* nOut;                           // final result
	int i;
	
	readFile(filename, theKnight, nEvent, arrEvent);
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;
	int P;
	int max = theKnight.HP;
	bool Arthur = false;
	bool Lancelot = false;
	bool Paladin = false;
	bool DragonKnight = false;
	bool Excalibur = false;
	bool Mythril = false;
	bool Excalipoor = false;
	bool flag = false;
	bool exit = false;
	bool DragonSword = false;
	bool win = false;
	bool lose = false;
	bool firstTime = true;

	int fibo1=0;
	int fibo2=1;
	int iodin=0;
	int ifrog=0;
	int itiny=0;
	int i1;

	if (max == 999){
		Arthur = true;
	}
	
	else if (max == 888){
		Lancelot = true;
	}
	
	else if (isPrimeNumber(max)){
		Paladin = true;
	}
	
	else if (isDragonKnight(max)){
		DragonKnight = true;
	}
	
	for (i = 0, i1 = 1; i < nEvent; i++, i1++)
	{
		int theEvent = arrEvent[i];
		//cout << theEvent << endl;
		float baseDamage;
		int b, level0;
		
		int temp3 = theKnight.level;

		//lancelot
		if (Lancelot){
			//cout << "This is Lancelot" << endl;
			if (theKnight.level%2!=0) Arthur = true;
			else Arthur = false;
		}

		switch (theEvent)
		{
		case MADBEAR:
			//deal with MadBear here
			baseDamage = 1;
			break;

		case BANDIT:
			//deal with Bandit here
			baseDamage = 1.5;
			break;
		
		case LORDLUPIN:
			baseDamage = 4.5;
			break;
		
		case ELF:
			baseDamage = 6.5;
			break;
		
		case TROLL:
			baseDamage = 8.5;
			break;
			
		case VAJSH:
			if (ifrog==0 && itiny==0){
				b = i1%10;
				level0 = (i1>6)?(b>5?b:5):b;
				if (((theKnight.level > level0)&&!Excalipoor)||iodin||DragonSword||Arthur){
					theKnight.level+=2;
					if (theKnight.level>10) theKnight.level = 10;
				}
				else if (theKnight.level < level0){
					ifrog = 4;
					theKnight.level = 1;
					if (theKnight.maidenkiss >=1){
						theKnight.level = temp3;
						theKnight.maidenkiss--;
						ifrog = 0;
					} 
				}
			}
			break;
			
		case SHAMAN:
			if (ifrog==0 && itiny==0){
				b = i1%10;
				level0 = (i1>6)?(b>5?b:5):b;
				if (((theKnight.level > level0)&&!Excalipoor)||iodin||DragonSword||Arthur){
					theKnight.level+=2;
					if (theKnight.level>10) theKnight.level = 10;
					//cout << "Excalipoor: " << Excalipoor << endl;
				}
				else if (theKnight.level < level0||Excalipoor){
					itiny = 4;
					theKnight.HP = theKnight.HP / 5;
					if (theKnight.HP < 5) theKnight.HP = 1;
					if (theKnight.remedy>=1){
						theKnight.HP*=5;
						theKnight.remedy--;
						itiny = 0;
					} 
				}
			}
			break;
			
		case EXCALIBUR:
			Excalibur = true;
			Excalipoor = false;
			if (DragonSword) Excalibur = false;
			break;
		
		case MYTHRIL:
			Mythril = true;
			break;
		
		case EXCALIPOOR:
			if (Arthur||Paladin||DragonKnight||iodin||theKnight.level>=5) {
				/*
				cout << "iodin: " << iodin << endl;
				cout << "Paladin: " << Paladin << endl;
				cout << "Dragon Knight: " << DragonKnight << endl;
				cout << "Arthur: " << Arthur << endl;
				cout << "theKnight.level: " << theKnight.level << endl;
				*/
				break;
			}
			else{
				//cout << "Get Excalipoor" << endl;
				Excalipoor = true;
				Excalibur = false;
			}
			break;
			
		case MUSHMARIO:
			theKnight.HP+=50;
			if (theKnight.HP > max) theKnight.HP = max;
			break;
		
		case MUSHFIB: 
			while(1){
				int fibo = fibo1 + fibo2;
				if ((fibo) > theKnight.HP){
					theKnight.HP = fibo;
					if (theKnight.HP>max) theKnight.HP = max;
					break; 
				}
				else{
					fibo2 = fibo;
					fibo1 = fibo2;
				}
			}
			break;
			
		case MUSHGHOST:
			if (!Paladin&&!DragonSword&&!Mythril&&!iodin){
				if (theKnight.HP<51) theKnight.HP = 1;
				else theKnight.HP-=50;
			} 
			break;
			
		case MUSHKNIGHT:
			max+=50;
			if (max > 999) max =999;
			theKnight.HP = max;
			break;
		
		case REMEDY:
			theKnight.remedy++;
			if(theKnight.remedy>99) theKnight.remedy = 99;
			break;
			
		case MAIDENKISS:
			theKnight.maidenkiss++;
			if(theKnight.maidenkiss>99) theKnight.maidenkiss = 99;
			break;
			
		case PHOENIXDOWN:
			theKnight.phoenixdown++;
			if(theKnight.phoenixdown>99) theKnight.phoenixdown = 99;
			break;
			
		case MERLIN:
			if(itiny!=0) theKnight.HP = max;
			if(ifrog!=0) theKnight.level = temp3;
			theKnight.level+=1;
			if (theKnight.level>10) theKnight.level = 10;
			theKnight.HP = max;
			itiny = 0;
			ifrog = 0;
			break;
			
		case GUINEVERE:
			flag = true;
			break;
			
		case LIGHTWING:
			if (!flag){
				for (int i2=i; i2<=i+3; i2++){
					switch(arrEvent[i2]){
						case 0:
							win = true;
							break;
						case 20:
							win = true;
							break;
					}
				}
				iodin = 0;
				i+=3;
				i1+=3;
			}
			else win = true;
			break;
			
		case ODIN:
			if (firstTime){
				iodin = 4;
				firstTime = false;
			}
			break;	
		
		case DRAGONSWORD:
			if (DragonKnight) DragonSword = true;
			Excalibur = false;
			Excalipoor = false;
			break;
			
		case BOWSER:
			if (Arthur||Lancelot||(Paladin&&theKnight.level>=8)||theKnight.level==10&&!Excalipoor||DragonSword) theKnight.level=10;
			else lose = true;
			break;
			
		case SURRENDER:
			win = true;
			break;
			
		case ABYSS:
			if ((theKnight.level >= 7)||DragonSword||iodin);
			else lose = true;
			break;
		}
			
		
		//deal with event 1->5
		if (theEvent==1 || theEvent==2 || theEvent==3 || theEvent==4 || theEvent==5){
			b = i1%10;
			level0 = (i1>6)?((b>5)?b:5):b;
			if (((theKnight.level > level0)&&!Excalipoor)||Excalibur||iodin||DragonSword||Arthur){
				theKnight.level++;
				if (theKnight.level>10) theKnight.level = 10;
			}
			else if((theKnight.level < level0)||Excalipoor){
				if (!Mythril){
					int temp;
					temp = max;
					theKnight.HP = theKnight.HP - (baseDamage*level0*10);
					//cout << "HP sau khi danh: " << theEvent << " " << theKnight.HP << endl;
					if (theKnight.HP <= 0){
						if (theKnight.phoenixdown>=1){
							theKnight.HP = temp;
							theKnight.phoenixdown--;
						}
					}
				}
			}
		}
		
		if (itiny!=0){
			itiny--;
			if (itiny == 0) theKnight.HP *= 5;
			if (theKnight.HP>max) theKnight.HP = max;
		}	
		
		if (ifrog!=0){
			ifrog--;
			if (ifrog == 0) theKnight.level = temp3;
		}
		
		if (iodin) iodin--;

		
		
		//princess
		if (flag) i = i-2;
		if (i<-1) exit=true;
			
		if (theKnight.HP <= 0){
			if (theKnight.phoenixdown > 0){
				theKnight.HP = max;
				theKnight.phoenixdown--;
				if (itiny != 0){
					itiny=0;
					if (itiny == 0) theKnight.HP *= 5;
					if (theKnight.HP>max) theKnight.HP = max;
				}	
				if (ifrog != 0){
					ifrog=0;
					if (ifrog == 0) theKnight.level = temp3;
				}
			}
		}
		
		if(theKnight.HP < 0 && theKnight.phoenixdown <=0) lose = true;
		//cout << "event: " << theEvent << " HP: " << theKnight.HP << "Level: " << theKnight.level << "Arthur: " << Arthur << endl;
		if (win||lose||exit) break; 
		
	}
	
	P = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
	if (lose) P=-1;
	nOut = &P;
    display(nOut);
	return 0;
}

