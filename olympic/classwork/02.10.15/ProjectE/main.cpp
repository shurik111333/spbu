#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nearest.in");
    ofstream fout("nearest.out");
    int n, A;
    fin >> n >> A;
    int **dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[50000];
    }
    return 0;
}

