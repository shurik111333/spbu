#include <iostream>

using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int *a = new int[m], *b = new int[m], *f = new int[n], *ind = new int[n + 1];
    int p[102000] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        p[f[i]]++;
        ind[f[i]] = i;
    }
    bool imp = false;
    bool amb = false;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (p[b[i]] == 0)
        {
            imp = true;
            break;
        }
        if (p[b[i]] > 1)
        {
            amb = true;
        }
    }
    if (imp)
    {
        cout << "Impossible";
        return 0;
    }
    if (amb)
    {
        cout << "Ambiguity";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = ind[b[i]] + 1;
    }
    cout << "Possible\n";
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

