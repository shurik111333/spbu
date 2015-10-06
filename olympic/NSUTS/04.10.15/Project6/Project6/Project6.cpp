
#include <iostream>
#include <fstream>
#include <cmath>
#define eps 0.000001
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long n = 0;
	fin >> n;
	double a, b, c;
	for (long i = 0; i<n; i++) {
		fin >> a >> b >> c;
		/*double znam = a*b*c;
		double chis = a*b + b*c + c*a;
		//if (znam > chis && a > 1 && b > 1 && c > 1)
		if (((((1/a+1/b)<0.66666666666666666)&&((1/b+1/c)<0.66666666666666666)&&((1/c+1/a)<0.66666666666666666))||(znam > chis)) && a > 1 && b > 1 && c > 1)
			fout << "YES\n";
		else
			fout << "NO\n";*/
		int x = 100;
		double y = a* x / b;
		double z = a * x / c;
		if (x + y + z < a*x)
			fout << "YES" << endl;
		else
			fout << "NO" << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
