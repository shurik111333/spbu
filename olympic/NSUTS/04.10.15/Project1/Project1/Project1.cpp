// Project1.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	fin >> n >> m;
	double x[110000] = {}, y[110000] = {};
	for (int i = 0; i < n; i++)
	{
		fin >> x[i] >> y[i];
	}
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i < m; i++)
	{
		fin >> x1 >> y1 >> x2 >> y2;
		double a = y2 - y1;
		double b = x1 - x2;
		double c = -a * x1 - b * y1;
		for (int j = 0; j < n; j++)
		{
			if ((a * x[j] + b * y[j] + c) > 0)
			{
				double t = (-a * x[j] - b * y[j] - c) / (a * a + b * b);
				x[j] = x[j] + 2 * t * a;
				y[j] = y[j] + 2 * t * b;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		fout << setprecision(12) << x[i] << " " << setprecision(12) << y[i] << endl;
	}
	return 0;
}