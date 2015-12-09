#include <iostream>
#include <fstream>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    long long result = 0;
    while (!fin.eof())
    //for (int i = 0; i < 2; i++)
    {
        int a, b, c;
        char x;
        fin >> a >> x >> b >> x >> c;
        result += a * b * c + 2 * (a + b + c - max(a, max(b, c)));
        //result += 2 * a * b + 2 * a * c + 2 * b * c + min(a * b, min(b * c, a * c));
    }
    fout << result;
    return 0;
}

