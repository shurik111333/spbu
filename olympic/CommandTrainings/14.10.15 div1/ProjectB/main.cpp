#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fin("bureau.in");
    //ifstream fout("bureau.out");
    int n = 0;
    string s[1000];
    bool f[0000] = {};
    fin >> n;
    for (int i =0; i < n; i++)
    {
        fin >> s[i];
        if (s[i] == "cancel")
            fin >> s[i];
    }
    return 0;
}

