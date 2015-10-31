#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char *str = new char[n];
    cin >> str;
    char p[500] = {};
    bool q[500] = {};
    for (int i = 'a'; i <= 'z'; i++)
    {
        p[i] = i;
    }
    /*for (int i = 0; i < n; i++)
    {
        q[str[i]] = true;
    }*/
    for (int i = 0; i < m; i++)
    {
        char a, b;
        cin >> a >> b;
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (p[i] == a)
                p[i] = b;
            else
                if (p[i] == b)
                    p[i] = a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[str[i]];
    }
    return 0;
}

