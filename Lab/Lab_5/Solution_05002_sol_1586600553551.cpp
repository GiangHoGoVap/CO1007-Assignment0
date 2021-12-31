#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

ifstream ifs;

struct POINT
{
  float x;
  float y;
};

void display(POINT *p)
{
  if (p != NULL)
  {
    cout << p->x << endl;
    cout << p->y << endl;
    delete p;
  }
}

POINT *readPoint()
{
  float x = 0, y = 0;
  ifs >> x;
  ifs >> y;
  POINT *point = new POINT;
  point->x = x;
  point->y = y;
  return point;
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  POINT *p = readPoint();
  display(p);
  delete p;

  ifs.close();
  return 0;
}