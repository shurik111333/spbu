#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 90000;

int gcd(int a, int b, FILE *file)
{
    if (b == 0)
    {
        return a;
    }
    /*fputs(a, file);
    fputs(" = ", file);
    fputs(b, file);
    fputs(" * ", file);
    fputs(a / b, file);
    fputs(" + ", file);
    fputs(a % b, file);
    fputs("\n", file);*/
    fputs(a.ToString());
    gcd(b, a % b, file);
}

int main()
{
    /*int a[maxN + 1] = {};
    for (int i = 2; i < maxN; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 2 * i; j <= maxN; j += i)
            {
                if (j == 411)
                {
                    cout << i << endl;
                }
                a[j] = 1;
            }
        }
    }
    cout << a[411] << endl;
    cout << a[613] << endl;
    cout << 65 % 7 << endl;*/
    FILE *file = fopen("file.txt", "w");
    gcd(27, 13, file);
    return 0;
}

