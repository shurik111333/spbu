#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[3][3];
int b[3][3];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool answer;

void gen(int k, int x, int y)
{
    b[x][y] = k;
    if (k == 9)
        answer = true;
    if (answer)
        return;
    for (int i = 0; i < 4; i++)
    {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (!(x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3))
                continue;
            if (b[x1][y1] == 0 && (a[x1][y1] == -1 || a[x1][y1] == k + 1))
                gen(k + 1, x1, y1);
            if (answer)
                return;
    }
    b[x][y] = 0;
}

int main()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = 0;
            char c;
            cin >> c;
            if (c == '?')
                a[i][j] = -1;
            else
                a[i][j] = c - '0';
        }
    answer = false;
    gen(1, 1, 1);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << b[i][j];
        }
        cout << "\n";
    }
    return 0;
}

