using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Det
{
    class Poly
    {
        public static int size = 20;
        private int[,] a;

        public Poly()
        {
            a = new int[size, size];
        }

        public Poly(string p)
        {
            a = new int[size, size];
            Lexer l = new Lexer(p);
            Lexer.Token curr = l.Next();
            while (curr.t != Lexer.Type.EOF)
            {
                int m = 1;
                if (curr.t == Lexer.Type.minus)
                {
                    m = -1;
                    curr = l.Next();
                }
                if (curr.t == Lexer.Type.plus)
                    curr = l.Next();
                int num = 0;
                if (curr.t == Lexer.Type.a)
                {
                    num = curr.value * m;
                    curr = l.Next();
                }
                else
                    num = m;
                int px = 0;
                int py = 0;
                if (curr.t == Lexer.Type.x)
                {
                    curr = l.Next();
                    if (curr.t == Lexer.Type.power)
                    {
                        px = curr.value;
                        curr = l.Next();
                    }
                    else
                        px = 1;
                    //curr = l.Next();
                }

                if (curr.t == Lexer.Type.y)
                {
                    curr = l.Next();
                    if (curr.t == Lexer.Type.power)
                    {
                        py = curr.value;
                        curr = l.Next();
                    }
                    else
                        py = 1;
                }
                a[px, py] += num;
            }
        }

        public Poly(int x)
        {
            a = new int[size, size];
            a[0, 0] = x;
        }

        public int this[int i, int j]
        {
            get
            {
                return a[i, j];
            }
            set
            {
                a[i, j] = value;
            }
        }

        public static Poly operator *(Poly p1, Poly p2)
        {
            Poly res = new Poly();
            for (int i1 = 0; i1 < size; i1++)
                for (int i2 = 0; i2 < size; i2++)
                    for (int i3 = 0; i3 < size; i3++)
                        for (int i4 = 0; i4 < size; i4++)
                            if (i1 + i3 < size && i2 + i4 < size)
                                res[i1 + i3, i2 + i4] += p1[i1, i2] * p2[i3, i4];
            return res;
        }

        public static Poly operator -(Poly p1, Poly p2)
        {
            Poly res = new Poly();
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    res[i, j] = p1[i, j] - p2[i, j];
            return res;
        }

        public static Poly operator +(Poly p1, Poly p2)
        {
            Poly res = new Poly();
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    res[i, j] = p1[i, j] + p2[i, j];
            return res;
        }


        public override string ToString()
        {
            if (a == null)
                return "";
            StringBuilder res = new StringBuilder("");
            int count = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                for (int j = size - 1; j >= 0; j--)
                {
                    if (a[i, j] != 0)
                    {
                        string num = "";
                        if (count > 0)
                            num = a[i, j] > 0 ? " + " : " - ";
                        else
                            num = a[i, j] < 0 ? "-" : "";
                        if (Math.Abs(a[i, j]) > 1 || i + j == 0)
                            num += Math.Abs(a[i, j]).ToString();
                        /*if (count == 0)
                            res.Append(a[i, j].ToString());
                        else
                            res.Append(string.Format(" {0} {1}", a[i, j] > 0 ? '+' : '-', Math.Abs(a[i, j])));*/
                        res.Append(num);
                        if (i != 0)
                            res.Append("x");
                        if (i > 1)
                            res.Append("^" + i.ToString());
                        if (j != 0)
                            res.Append("y");
                        if (j > 1)
                            res.Append("^" + j.ToString());
                        count++;
                    }
                }
            }
            if (count == 0)
                res.Append("0");
            return res.ToString();
        }
    }
}
