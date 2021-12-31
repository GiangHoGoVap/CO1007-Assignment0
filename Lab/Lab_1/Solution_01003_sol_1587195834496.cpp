#include <iostream>
#include <fstream>
using namespace std;


int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	try
	{
		int edge1, edge2, edge3;
        ifs >> edge1 >> edge2 >> edge3;
        if (edge1 == edge2 && edge2 == edge3)
            printf("Equilateral triangle\n");
        else if (edge1 == edge2 || edge2 == edge3 || edge3 == edge1)
            printf("Isosceles triangle\n");
        else
            printf("Scalene triangle\n");
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}