#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");
ofstream fout("1.out");

int a[3];
char symb[3] = {'P', 'R', 'S'};
const char P = 'P';
const char S = 'S';
const char R = 'R';
const string impos = "IMPOSSIBLE\n";
bool error;
int size;
char ans[110000] = {};
int c;
int t, n;

char winner(char a, char b)
{
    if (a == '\0')
        return b;
    if (b == '\0')
        return a;
    switch (a)
    {
    case P:
        return b == S ? b : a;
    case R:
        return b == P ? b : a;
    case S:
        return b == R ? b : a;
    default:
        throw a;
    }
}

//char gen(int n, char win)
//{
//    if (error)
//        return '\0';
//    if (n == 1)
//    {
//        ans[c] = '\0';
//        bool f = true;
//        for (int i = 0; i < 3; i++)
//            if (a[i] > 0 && win != symb[i])
//            {
//                ans[c++] = symb[i];
//                a[i]--;
//                f = false;
//                break;
//            }
//        if (f)
//        {
//            error = true;
//            return '\0';
//        }
//        return winner(win, ans[c - 1]);
//    }
//    char lastW = gen(n / 2, '\0');
//    return winner(lastW, gen(n / 2, lastW));
//}
bool answer;
const char *getP(char c)
{
    switch (c)
    {
    case P:
        return "PR";
    case R:
        return "RS";
    case S:
        return "PS";
    }
}

int *gen(char c, string &res)
{
    int *ans = new int[3];
    ans[0] = ans[1] = ans[2] = 0;
    string t;
    res = "";
    //res.push_back(c);
    t.push_back(c);
    for (int i = 0; i < n; i++)
    {
        res = "";
        for (char q : t)
            res.append(getP(q));
        t = "";
        for (int i = 0; i < res.length(); i += 2)
        {
            string s1(getP(res[i]));
            string s2(getP(res[i + 1]));
            if (s1 < s2)
            {
                t.push_back(res[i]);
                t.push_back(res[i + 1]);
            }
            else
            {
                t.push_back(res[i + 1]);
                t.push_back(res[i]);
            }
        }
    }
    for (char q : res)
    {
        switch (q)
        {
        case P:
            ans[0]++;
            break;
        case R:
            ans[1]++;
            break;
        case S:
            ans[2]++;
            break;
        }
    }
    return ans;
}

string s1[100];

int main()
{
    fin >> t;

    for (int q = 0; q < t; q++)
    {
        fout << "Case #" << q + 1 << ": ";
        fin >> n >> a[0] >> a[1] >> a[2];
        answer = false;
        size = (1 << n);
        int c = 0;
        for (int qq = 0; qq < 3; qq++)
        {
            string s;
            int *ans = gen(symb[qq], s);
            if (ans[0] == a[0] && ans[1] == a[1] && ans[2] == a[2])
            {
                answer = true;
                assert(s.length() == size);
                s1[c++] = s;
            }
        }
        if (!answer)
            fout << impos;
        else
        {
            string s = s1[0];
            for (int i = 1; i < c; i++)
                if (s1[i] < s)
                    s = s1[i];
            fout << s << "\n";
        }
    }
    cout << "OK";
    return 0;
}

