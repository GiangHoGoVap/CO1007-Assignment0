/*****Version 1.1***********/
#include <iomanip>
#include <iostream>
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

bool IsPrime(int number) {
    bool check = true;
    for(int i = 2; i <= number / 2; ++i)
        if(number % i == 0)
        {
            check = false;
            break;
        }
    return check;
}

void display(float fOut)
//display value of fOut in format of 0.XX
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

int calculateRealHP(int baseHP, int wp, int ground){
    int realHP = 0;
    if(wp == 0 && ground == baseHP){
        realHP = baseHP/10*1.1;
    }
    else if(wp == 0 && ground != baseHP){
        realHP = baseHP/10;
    }
    else if(wp == 1 && ground == baseHP){
        realHP = baseHP*1.1;
    }
    else if(wp == 1 && ground != baseHP){
        realHP = baseHP;
    }
    else if(wp == 2 && ground == baseHP){
        realHP = baseHP*1.1;
    }
    else if(wp == 2 && ground != baseHP){
        realHP = baseHP;
    }
    else if(wp == 3 && ground == baseHP){
        realHP = baseHP*1.1*2;
    }
    else{
        realHP = baseHP*2;
    }
    if (realHP > 999){
        return 999;
    }
    else{
        return realHP;
    }
}

float calculateResult(int realHP1, int realHP2){
    float result = ((float(realHP1) - float(realHP2) + 999)/2000);
    return (roundf(result * 100) / 100);

}

int main(int argc, char** argv)
{

    if (argc < 2) return 1;

    const char* filename = argv[1];
    cout << filename << endl;

    int baseHP1,baseHP2, wp1, wp2, ground, realHP1, realHP2;
    float fOut = 0.00;
    readFile(filename, baseHP1, baseHP2, wp1, wp2, ground);

    if (baseHP1 == 999) {
        fOut = 1;
    }
    else if (baseHP2 == 888){
        fOut = 0.00;
    }
    else if (IsPrime(baseHP1) == true && IsPrime(baseHP2) == false ){
        fOut = 0.99;
    }
    else if (IsPrime(baseHP1) == false && IsPrime(baseHP2) == true){
        fOut = 0.01;
    }
    else if (IsPrime(baseHP1) == true && IsPrime(baseHP2) == true){
        if(baseHP1 > baseHP2){
            fOut = 0.99;
        }
        else if(baseHP1 < baseHP2){
            fOut = 0.01;
        }
        else{
            fOut = 0.50;
        }
    }
    else{
        if (wp2 == 3){
            realHP2 = calculateRealHP(baseHP2,1,ground);
        }
        else{
            realHP2 = calculateRealHP(baseHP2,wp2,ground);
        }
        realHP1 = calculateRealHP(baseHP1,wp1,ground);
        if (realHP1 > realHP2 && wp2 == 2){
            fOut = 0.50;
        }
        else if(realHP1 < realHP2 && wp1 == 2){
            fOut = 0.50;
        }
        else{
            fOut = calculateResult(realHP1,realHP2);
        }
    }

    display(fOut);

    return 0;
}
