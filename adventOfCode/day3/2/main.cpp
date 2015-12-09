#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

const int size = 10000;

int main()
{
    int **a = new int*[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }
    int x[2] = {5000, 5000};
    int y[2] = {5000, 5000};
    a[x[0]][y[0]] = 1;
    int result = 1;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    //while (!fin.eof())
    for (int i = 0; i < 8192; i++)
    {
        char c;
        fin >> c;
        switch (c)
        {
        case '>':
        {
            y[i % 2]++;
            break;
        }
        case '<':
        {
            y[i%2]--;
            break;
        }
        case '^':
        {
            x[i%2]--;
            break;
        }
        case 'v':
        {
            x[i%2]++;
            break;
        }
        }
        if (a[x[i%2]][y[i%2]] == 0)
            result++;
        a[x[i%2]][y[i%2]]++;
        //assert(x >= 0 && x < size && y >= 0 && y < size);
    }
    cout << result;
    return 0;
}

