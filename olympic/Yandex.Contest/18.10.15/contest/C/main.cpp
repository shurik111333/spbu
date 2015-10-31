#include <iostream>
#include <cmath>

using namespace std;

int xRes, yRes;

double dist(int x1, int y1)
{
    return (sqrt((x1 - xRes)*(x1 - xRes) + (y1 - yRes)*(y1 - yRes)));
}

int main()
{
   int x1 = 0, y1 = 0, x2 = 1000000000, y2 = 1000000000, xm, ym;
   int ans = 0;
   /*xm = (x1 + x2) / 2;
   ym = (y1 + y2) / 2;
   xRes = 17;
   yRes = 239;
   int xCurr = (x1 + x2) / 2, yCurr = (y1 + y2) / 2, xPrev = xRes, yPrev = yRes;
   while (x2 - x1 > 1 && y2 - y1 > 1)
   {

       xm = (x1 + x2) / 2;
       ym = (y1 + y2) / 2;
       cout << xm << " " << ym << endl;
       xCurr = xm;
       yCurr = ym;
       cout.flush();
       if (cin.eof())
       {
            return 0;
       }
       cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;
       cin >> ans;

       cout << (xm + x1) / 2 << " " << (ym + y1) / 2 << endl;
       xPrev = xCurr;
       yPrev = yCurr;
       xCurr = (xm + x1) / 2;
       yCurr = (ym + y1) / 2;
       cout.flush();
       //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
       if (cin.eof())
            return 0;
        cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;
       cin >> ans;
       //if (dist())
       if (ans == 1)
       {
           y2 = ym;
           x2 = xm;
           continue;
       }
        cout << xm << " " << ym << endl;
        xPrev = xCurr;
        yPrev = yCurr;
        xCurr = xm;
        yCurr = ym;
        cout.flush();
        if (cin.eof())
             return 0;

        cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       cout << (xm + x1) / 2 << " " << (ym + y1) / 2 + ym << endl;
       xPrev = xCurr;
       yPrev = yCurr;
       xCurr = (xm + x1) / 2;
       yCurr = (ym + y1) / 2 + ym;
       cout.flush();
      // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
       if (cin.eof())
            return 0;

       cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       if (ans == 1)
       {

           x2 = xm;
           y1 = ym;
           continue;
       }

        cout << xm << " " << ym << endl;
        cout.flush();
        if (cin.eof())
             return 0;

        cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       cout << (xm + x1) / 2 + xm << " " << (ym + y1) / 2 + ym << endl;
       cout.flush();
      // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
       if (cin.eof())
            return 0;

       cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       if (ans == 1)
       {

           x1 = xm;
           y1 = ym;
           continue;
       }
       cout << xm << " " << ym << endl;
       cout.flush();
       if (cin.eof())
            return 0;

       cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       cout << (xm + x1) / 2 + xm << " " << (ym + y1) / 2 << endl;
       cout.flush();
//       cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
       if (cin.eof())
            return 0;

       cout << dist(xCurr, yCurr) << " " << dist(xPrev, yPrev) << endl;

       cin >> ans;
       if (ans == 1)
       {

           x1 = xm;
           y2 = ym;
           continue;
       }
       x1 = (3 * (xm - x1) / 4);
       x2 = (x2 - xm) / 4 + xm;
       y1 = (3 * (ym - y1) / 4);
       y2 = (y2 - ym) / 4 + ym;

   }
   while (true)
   {
       if (x1 == x2)
       {
           if (y2 == y1)
           {
               cout << "A " << x1 << " "<< y1 << endl;
           cout.flush();
           }
           else
              {
                 cout << x1 << " " << y1 << endl;
                 cout.flush();
                 if (cin.eof())
                      return 0;
                 cin >> ans;
                 cout << x1 << " " << y2 << endl;
                 cout.flush();
                 if (cin.eof())
                      return 0;
                 cin >> ans;
                 if (ans == 1)
                    {

                     cout << "A " << x1 << " " << y2 << endl;
                     cout.flush();
                     if (cin.eof())
                          return 0;
                 }
                 else
                 {
                     cout << "A " << x1 << " " << y1 << endl;
                     cout.flush();
                     if (cin.eof())
                          return 0;
                 }
           }
          return 0;
       }
       if (y1 == y2)
       {
           cout << x1 << " " << y1 << endl;
           cout.flush();
           if (cin.eof())
                return 0;
           cin >> ans;
           cout << x2 << " " << y1 << endl;
           cout.flush();
           if (cin.eof())
                return 0;
           cin >> ans;
           if (ans == 1)
               cout << "A " << x2 << " " << y2 << endl;
           else
               cout << "A " << x1 << " " << y1 << endl;
           cout.flush();

           return 0;
       }
        cout << x1 << " " << y1 << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        cout << x1 << " " << y2 << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        if (ans == 1)
        {
            y1 = y2;
        }
        else
        {
            y2 = y1;
        }
   }*/
    int xRes, yRes;
   int xl = 0;
   int xr = 1000000000;
   //int ans;
   while (xr - xl > 1)
   {
        int xm = (xr + xl) / 2;
        int xml = (xl + xm) / 2;
        int xmr = (xr + xm) / 2;
        cout << xml << " 0" << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        cout << xmr << " 0" << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        if (ans == 1)
        {
            xl = xm;
            continue;
        }
        else
        {
            xr = xm;
            continue;
        }
   }
   if (xl == xr)
       xRes = xl;
   else
   {
       cout << xl << " 0" << endl;
       cout.flush();
       if (cin.eof())
            return 0;
       cin >> ans;
       cout << xr << " 0" << endl;
       cout.flush();
       if (cin.eof())
            return 0;
       cin >> ans;
       if (ans == 1)
           xRes = xr;
       else
           xRes = xl;
   }


   int yl = 0;
   int yr = 1000000000;
   //int ans;
   while (yr - yl > 1)
   {
        int ym = (yr + yl) / 2;
        int yml = (yl + ym) / 2;
        int ymr = (yr + ym) / 2;
        cout << xRes << " " << yml << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        cout << xRes << " " << ymr << endl;
        cout.flush();
        if (cin.eof())
             return 0;
        cin >> ans;
        if (ans == 1)
        {
            yl = ym;
            continue;
        }
        else
        {
            yr = ym;
            continue;
        }
   }
   if (yl == yr)
       yRes = yl;
   else
   {
       cout << xRes << " " << yl << endl;
       cout.flush();
       if (cin.eof())
            return 0;
       cin >> ans;
       cout << xRes << " " << yr << endl;
       cout.flush();
       if (cin.eof())
            return 0;
       cin >> ans;
       if (ans == 1)
           yRes = yr;
       else
           yRes = yl;
   }
   cout << "A " << xRes << " " << yRes << endl;
   cout.flush();
   return 0;
}

