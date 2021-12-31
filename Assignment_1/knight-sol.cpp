#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

#define minLevel 1
#define maxLevel 10
#define minQuantity 0
#define maxQuantity 99

const int MADBEAR = 1;
const int BANDIT = 2;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

int constrain(int x, int min, int max) {
	if (x < min) return min;
  	if (x > max) return max;
  	return x;
}

enum knightType {
  	Arthur,
  	Lancelot,
  	Paladin,
  	Dragon,
  	Normal
};

struct knight
{
   int HP;
   int maxHP;
   int level;
   int remedy;
   int maidenkiss;
   int phoenixdown;
   knightType type;
   bool mini = false;
   int miniWaiting = 0;
   bool fog = false;
   int fogWaiting = 0;
   int *levelRestore = nullptr;
   int sword = false; // -1: excalipoor, 0: normal, 1: excalibur, 2: dragon
   bool mythril = false;
   bool lightwing = false;
   int lightwingCount = 0;
   bool odin = false;
   int odinCount = 0;
   bool recuseSuccess = false;

   int getSum() {
     // TODO
     return this->HP + this->level + this->remedy + this->maidenkiss + this->phoenixdown;
   }

   bool revive() {
     // TODO
     if (this->phoenixdown) {
       this->delMini();
       this->delFog();

       // this->sword = false;
       // this->mythril = false;
       // this->lightwing = false;
       // this->lightwingCount = 0;
       // this->odin = false;
       // this->odinCount = 0;

       this->HP = this->maxHP;
       this->phoenixdown -= 1;
       return 1;
     }
     return 0;
   }

   bool use_remedy() {
     if (this->remedy) {
       this->delMini();
       this->remedy -= 1;
       return 1;
     }
     return 0;
   }

   bool use_maidenkiss() {
     if (this->maidenkiss) {
       this->delFog();
       this->maidenkiss -= 1;
       return 1;
     }
     return 0;
   }

   void anunalCheck() {
     if (this->mini && (!this->lightwing)) {
       this->miniWaiting -= 1;
       if (this->miniWaiting == 0) {
         this->delMini();
       }
     }

     if (this->fog) {
       this->fogWaiting -= 1;
       if (this->fogWaiting == 0) {
         this->delFog();
       }
     }

     if (this->odin) {
       this->odinCount -= 1;
       if (this->odinCount == 0) {
         this->odinCount -= 1;
         this->odin = false;
       }
     }
   }

   bool setMini() {
     this->mini = true;
     this->miniWaiting += 3;
     if (!this->mythril) {
       int newHP = this->HP < 5 ? 1 : (this->HP / 5);
       this->HP = constrain(newHP, 0, this->maxHP);
     }
     return !this->use_remedy();
   }

   bool delMini() {
     this->mini = false;
     this->miniWaiting = 0;
     // if (!this->mythril) {
       this->HP = constrain(this->HP * 5, 0, this->maxHP);
     // }
   }

   bool setFog() {
     this->fog = true;
     this->fogWaiting += 3;
     this->levelRestore = new int();
     *this->levelRestore = this->level;
     this->level = 1;
     return !this->use_maidenkiss();
   }

   bool delFog() {
     this->fog = false;
     this->fogWaiting = 0;
     if (this->levelRestore) {
       this->level = *this->levelRestore;
       delete this->levelRestore;
       this->levelRestore = nullptr;
     }
   }

   bool checkStatus() {
     // TODO
     if (this->HP == 0) {
       return this->revive();
     }
     return 1;
   }
};

float baseDamage[] = {0, 1, 1.5, 4.5, 6.5, 8.5};

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

bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}

// Returns true if n is a Fibinacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perferct square
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}

int nearestFibo(int n) {
  if (isFibonacci(n+1)) return n+1;
  return nearestFibo(n+1);
}

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    int max = sqrt(n);
    for (int i = 2; i < max; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool isSquareTriangle(int x) {
  if (x%2 != 0) return false;
  int temp = 0;

  for (int i = 1; i < x - 1; i++) {
    if ((x*x/2) % i == 0) {
      temp = (int) ((x*x/2) / i);
      if (x - temp < i && x - temp > 0) {
        // cout << x - i << '\t' << x - temp << '\t' << i + temp - x << '\n';
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char* argv[])
{
  if (argc < 2) return 1;
    const char* filename = argv[1];

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;
   int i;

   readFile(filename, theKnight, nEvent, arrEvent);
   theKnight.maxHP = theKnight.HP;
   // cout << nEvent << endl;
   for (i = 1; i <= nEvent; i++)
   {
       int theEvent = arrEvent[i - 1];
       //cout << "Event: " << theEvent << endl;
       //cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;

       if (i == 1) {
         if (theKnight.maxHP == 999) {
           theKnight.type = Arthur;
         } else if (theKnight.maxHP == 888) {
           theKnight.type = Lancelot;
         } else if (isPrime(theKnight.maxHP)) {
           theKnight.type = Paladin;
         } else if (isSquareTriangle(theKnight.maxHP)) {
           theKnight.type = Dragon;
         } else {
           theKnight.type = Normal;
         }
       }

       if (theEvent == 0) {
         nOut = new int();
         *nOut = theKnight.getSum();
         break;
       }

       if (theKnight.lightwing) {
         if (theEvent == 20 || theKnight.recuseSuccess) {
           nOut = new int();
           *nOut = theKnight.getSum();
           break;
         }
         theKnight.lightwingCount -= 1;
         if (theKnight.lightwingCount == 0) {
           theKnight.lightwing = false;
         }
       } else if (theEvent > 0 && theEvent <= 5) {
         int b = i % 10;
         int levelO = i > 6 ? (b > 5 ? b : 5) : b;

         if (((theKnight.type == Paladin || (theKnight.type == Dragon && theKnight.sword == 2) || theKnight.level > levelO || theKnight.sword == 1) && theKnight.sword != -1) || theKnight.odin || theKnight.type == Arthur || (theKnight.type == Lancelot && theKnight.level%2 != 0)) {
           theKnight.level = constrain(theKnight.level + 1, minLevel, maxLevel);
           // if (theKnight.odin) theKnight.miniWaiting += 1;

         } else if (theKnight.level < levelO || theKnight.sword == -1) {
           if (!theKnight.mythril) {
             int damage = baseDamage[theEvent] * levelO  * 10;
             theKnight.HP = constrain(theKnight.HP - damage, 0, theKnight.maxHP);
             if (theKnight.checkStatus() == 0) {
               nOut = new int();
               *nOut = -1;
               break;
             }
           }
         }
       } else if (theEvent == 6) {
           if (!theKnight.mini && !theKnight.fog) {
               int b = i % 10;
               int levelO = i > 6 ? (b > 5 ? b : 5) : b;

               if (((theKnight.type == Paladin || (theKnight.type == Dragon && theKnight.sword == 2) || theKnight.level > levelO) && theKnight.sword != -1) || theKnight.odin || theKnight.type == Arthur || (theKnight.type == Lancelot && theKnight.level % 2 != 0)) {
                   theKnight.level = constrain(theKnight.level + 2, minLevel, maxLevel);
                   // if (theKnight.odin) theKnight.miniWaiting += 1;

               }
               else if (theKnight.level < levelO || theKnight.sword == -1) {
                   theKnight.setMini();
                   continue;
               }
            }
         
       } else if (theEvent == 7) {
           if (!theKnight.mini && !theKnight.fog) {

               int b = i % 10;
               int levelO = i > 6 ? (b > 5 ? b : 5) : b;
               // if (theKnight.odin) theKnight.miniWaiting += 1;

               if (((theKnight.type == Paladin || (theKnight.type == Dragon && theKnight.sword == 2) || theKnight.level > levelO) && theKnight.sword != -1) || theKnight.odin || theKnight.type == Arthur || (theKnight.type == Lancelot && theKnight.level % 2 != 0)) {
                   theKnight.level = constrain(theKnight.level + 2, minLevel, maxLevel);

               }
               else if (theKnight.level < levelO || theKnight.sword == -1) {
                   theKnight.setFog();
                   continue;
               }
           }
       } else if (theEvent == 8) {
         if (theKnight.type != Dragon || theKnight.sword != 2)
           theKnight.sword = true;
       } else if (theEvent == 9) {
         theKnight.mythril = true;
       } else if (theEvent == 10) {
         if (theKnight.level < 5 && theKnight.type != Arthur && (theKnight.type != Lancelot || theKnight.level%2 == 0) && theKnight.type != Paladin && theKnight.type != Dragon && !theKnight.odin)
           theKnight.sword = -1;
       } else if (theEvent == 11) {
         theKnight.HP = constrain(theKnight.HP + 50, 0, theKnight.maxHP);
       } else if (theEvent == 12) {
         theKnight.HP = constrain(nearestFibo(theKnight.HP), 0, theKnight.maxHP);
       } else if (theEvent == 13) {
         if (theKnight.type != Paladin && (theKnight.type != Dragon || theKnight.sword != 2) && !theKnight.mythril && !theKnight.odin)
           theKnight.HP = constrain(theKnight.HP - 50, 1, theKnight.maxHP);
       } else if (theEvent == 14) {
         theKnight.maxHP = constrain(theKnight.maxHP + 50, 0, 999);
         theKnight.HP = theKnight.maxHP;
       } else if (theEvent == 15) {
         theKnight.remedy = constrain(theKnight.remedy + 1, minQuantity, maxQuantity);
       } else if (theEvent == 16) {
         theKnight.maidenkiss = constrain(theKnight.maidenkiss + 1, minQuantity, maxQuantity);
       } else if (theEvent == 17) {
         theKnight.phoenixdown = constrain(theKnight.phoenixdown + 1, minQuantity, maxQuantity);
       } else if (theEvent == 18) {
         if (theKnight.mini) {
           theKnight.delMini();
         }
         if (theKnight.fog) {
           theKnight.delFog();
         }
         theKnight.level = constrain(theKnight.level + 1, minLevel, maxLevel);
         theKnight.HP = theKnight.maxHP;
       } else if (theEvent == 19) {
         if (theKnight.level < 7 && (theKnight.type != Dragon || theKnight.sword != 2)  && !theKnight.odin) {
           nOut = new int();
           *nOut = -1;
           break;
         }
       } else if (theEvent == 20) {
         theKnight.recuseSuccess = true;
         nEvent = (i-1) * 2 + 1;
         int* newArrEvent = new int[nEvent];

         for (int j = 0; j < i; j++) {
           newArrEvent[j] = arrEvent[j];
         }
         for (int j = i; j < nEvent; j++) {
           newArrEvent[j] = arrEvent[nEvent - j - 1];
         }
         delete[] arrEvent;
         arrEvent = newArrEvent;
       } else if (theEvent == 21) {
         theKnight.lightwing = true;
         theKnight.lightwingCount = 3;
       } else if (theEvent == 22) {
           if (theKnight.odin == false && theKnight.odinCount != -1) {
               theKnight.odin = true;
               theKnight.odinCount = 4;
           }
       } else if (theEvent == 23) {
         if (theKnight.type == Dragon) {
           theKnight.sword = 2;
         }
       } else if (theEvent == 99) {
         if (((theKnight.type == Arthur || theKnight.type == Lancelot || (theKnight.type == Paladin && theKnight.level >= 8) ||
             (theKnight.type == Normal && theKnight.level  == 10)) && theKnight.sword != -1)
              || (theKnight.type == Dragon && theKnight.sword == 2) ) {
               theKnight.level = 10;
             } else {
               nOut = new int();
               *nOut = -1;
               break;
             }
       }

       theKnight.anunalCheck();
   }

   if (i == nEvent + 1) {
     nOut = new int();
     *nOut = theKnight.getSum();
   }

   display(nOut);

   return 0;
}
