#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin("intersec1.in");
	ofstream fout("intersec1.out");
	int a1, b1, c1, a2, b2, c2;
	fin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	fout << setprecision(20) << 1.0 * (b2 * c1 - b1 * c2) / (a2 * b1 - b2 * a1) << " " <<
	        1.0 * (c1 * a2 - c2 * a1) / (b2 * a1 - a2 * b1);
	return 0;
}
