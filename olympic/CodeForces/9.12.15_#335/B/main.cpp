#include <iostream>
#include <cstring>

using namespace std;

char s[110000] = {};
//int q[200] = {};
int ans[110000] = {};

int main()
{
    int x, y, x0, y0;
    cin >> x >> y >> x0 >> y0;
    int x1 = x0, y1 = y0;
    int **field = new int*[x + 1];
    for (int i = 1; i <= x; i++)
    {
        field[i] = new int[y + 1];
        for (int j = 1; j <= y; j++)
        {
            field[i][j] = 0;
        }
    }
    cin >> s;
    int len = strlen(s);
    field[x1][y1] = 1;
    int count = 1;
    ans[0] = 1;
    for (int i = 0; i < len; i++)
    {
        ans[i + 1] = 1;
        switch (s[i])
        {
        case 'U':
        {
            if (x1 > 1)
            {
                x1--;
            }
            break;
        }
        case 'D':
        {
            if (x1 < x)
            {
                x1++;
            }
            break;
        }
        case 'L':
        {
            if (y1 > 1)
                y1--;
            break;
        }
        case 'R':
        {
            if (y1 < y)
                y1++;
            break;
        }
        }
        if (field[x1][y1] == 0)
            count++;
        else
            ans[i + 1] = 0;
        field[x1][y1] = 1;
    }
    ans[len] += x * y - count;
    for (int i = 0; i <= len; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

