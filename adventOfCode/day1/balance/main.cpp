#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

char input[100000] = {};

int main()
{
    ifstream fin("in.txt");
    fin >> input;
    int balance = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        balance += input[i] == '(' ? 1 : -1;
        if (balance < 0)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    //cout << balance;
    return 0;
}

