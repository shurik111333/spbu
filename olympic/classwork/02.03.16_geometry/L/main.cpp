#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
	ifstream fin("line2.in");
	ofstream fout("line2.out");
	long long x1, y1, x2, y2; 
	cin >> x1 >> y1 >> x2 >> y2;
	long long a = x2;
	long long b = y2;
	cout << a << " " << b << " " << -a*x1 - b*y1;
	return 0;
}
