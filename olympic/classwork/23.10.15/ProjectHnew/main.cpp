#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char currLine[100100] = {};
int k = 53;
const int mapSize = 1000000;
long long map1[mapSize] = {};
long long map2[mapSize] = {};
int values[mapSize] = {};
char *names[mapSize] = {};
const int p1 = 997;
const int mod1 = 1000000000 + 7;
const int p2 = 41;
const int mod2 = 1000000000 + 9;
int hash1, hash2;

void getHash(char *str, int len)
{
    hash1 = str[0];
    hash2 = str[0];
    for (int i = 1; i < len; i++)
    {
        hash1 = (hash1 * p1 + str[i]) % mod1;
        hash2 = (hash2 * p2 + str[i]) % mod2;
    }
}

/*bool isEqual(char *str1, char *str2)
{
    int index = 0;
    while (str1[index] != '\0' && str2[index] != '\0' && str1[index] == str2[index])
        index++;
    return str1[index] == str2[index];
}*/

int add(char *str, int len, int hash1, int hash2, int count)
{
    int currIndex = (hash1) % mapSize;
    while (names[currIndex] != nullptr)
    {
        if (map1[currIndex] == hash1 && map2[currIndex] == hash2)
            //if (strcmp(str, names[currIndex]) == 0)
            {
                values[currIndex] += count;
                return values[currIndex];
            }
        currIndex += k;
        if (currIndex >= mapSize)
            currIndex -= mapSize;
    }
    map1[currIndex] = hash1;
    map2[currIndex] = hash2;
    names[currIndex] = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        names[currIndex][i] = str[i];
    }
    names[currIndex][len] = '\0';
    values[currIndex] = count;
    return count;
}

int main()
{
    ifstream fin("incrementator.in");
    ofstream fout("incrementator.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    while (!fin.eof())
    {
        fin >> currLine;
        if (fin.eof())
            break;
        int len = strlen(currLine);
        getHash(currLine, len);
        int count = 0;
        fin >> count;
        fout << add(currLine, len, hash1, hash2, count) << endl;
    }
    return 0;
}
