#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");

int c;
int t;
int k, m;
string s;
string s1[10];
bool error;
int p;
bool answer;

const string no = "NO\n";
const string yes = "YES\n";

void print()
{
    int p = 0;
    for (int i = 1; i < k; i++)
    {
        cout << s.substr(p, i) << "\n";
        p += i;
    }
    cout << s.substr(p, s.length() - p) << "\n";
}

bool correct(string s)
{
    bool res = true;
    for (int i = 1; i < c; i++)
        res &= (s != s1[i]);
    return res;
}

void gen(int ind)
{
    c = ind;
    if (ind > k)
    {
        if (p == s.length())
            answer = true;
        return;
    }
    for (int i = p + 1; i < s.length() - (k - ind) + 1; i++)
    {
        if (correct(s.substr(p, i - p)))
        {
            s1[ind] = s.substr(p, i - p);
            int p1 = p;
            p += i - p;
            gen(ind + 1);
            c = ind;
            p = p1;
            if (answer)
                return;
        }
    }
}

int main()
{
    cin >> t;
    for (int qq = 0; qq < t; qq++)
    {
        cin >> s >> k;
        if (s.length() < k)
        {
            cout << no;
            continue;
        }
        if (s.length() >= k * (k + 1) / 2)
        {
            cout << yes;
            print();
            continue;
        }
        p = 0;
        c = 0;
        answer = false;
        gen(1);
        if (!answer)
        {
            cout << no;
            continue;
        }
        cout << yes;
        for (int i = 0; i < k; i++)
            cout << s1[i + 1] << "\n";
//        if (k == 1)
//        {
//            cout << yes << s << "\n";
//        }
//        if (k == 2)
//        {
//            if (s[0] == s[1] && s.length() == 2)
//            {
//                cout << no;
//                continue;
//            }
//            cout << yes << s[0] << "\n" << s.substr(1, s.length() - 1) << "\n";
//        }
//        error = false;
//        c = 0;
//        int p = 0;
//        for (int i = 1; i < k; i++)
//        {
//            int l = 1;
//            while (p + l < s.length() && !correct(s.substr(p, l)))
//                l++;
//            if (p + l == s.length())
//            {
//                error = true;
//                cout << no;
//                break;
//            }
//            s1[i] = s.substr(p, l);
//            c++;
//            p += l;
//        }
//        if (error)
//            continue;
//        if (!correct(s.substr(p, s.length() - p)))
//        {
//            cout << no;
//            continue;
//        }
//        s1[k] = s.substr(p, s.length() - p);
//        cout << yes;
//        for (int i = 1; i <= k; i++)
//            cout << s1[i] << "\n";
    }
    return 0;
}

