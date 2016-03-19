using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Det
{
    class Lexer
    {
        private string s;
        int i;

        public struct Token
        {
            public Type t;
            public int value;

            public Token(Type t, int v = 0)
            {
                this.t = t;
                value = v;
            }
        }

        public enum Type
        {
            x,
            y,
            a,
            power,
            EOF,
            plus = '+',
            minus = '-'
        }

        public Lexer(string s)
        {
            this.s = s;
            i = 0;
        }

        private void SkipSpaces()
        {
            while (i < s.Length && s[i] == ' ')
                i++;
        }

        private int GetNumber()
        {
            int res = 0;
            while (i < s.Length && s[i] >= '0' && s[i] <= '9')
            {
                res = res * 10 + s[i] - '0';
                i++;
            }
            return res;
        }

        public Token Next()
        {
            SkipSpaces();
            if (i == s.Length)
                return new Token(Type.EOF);
            switch (s[i])
            {
                case '+':
                    i++;
                    return new Token(Type.plus);
                case '-':
                    i++;
                    return new Token(Type.minus);
                case 'x':
                    i++;
                    return new Token(Type.x);
                case 'y':
                    i++;
                    return new Token(Type.y);
                case '^':
                    i++;
                    return new Token(Type.power, GetNumber());
                default:
                    return new Token(Type.a, GetNumber());
            }
        }
    }

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

        public static Poly operator * (Poly p1, Poly p2)
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

    class Matrix
    {
        private int n;
        private Poly[,] a;

        public Matrix(int n)
        {
            this.n = n;
            a = new Poly[n, n];
        }

        public Matrix(int n, Poly[,] a)
        {
            this.n = n;
            this.a = a;
        }

        public Poly this[int i, int j]
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

        public Matrix Addition(int r, int c)
        {
            Matrix res = new Matrix(n - 1);
            int x1 = 0;
            int y1 = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == r)
                    continue;
                for (int j = 0; j < n; j++)
                {
                    if (j != c)
                    {
                        res[x1, y1] = a[i, j];
                        y1++;
                    }
                }
                x1++;
                y1 = 0;
            }
            return res;
        }

        public Poly Det()
        {
            if (n == 2)
                return a[0, 0] * a[1, 1] - a[0, 1] * a[1, 0];
            Poly res = new Poly();
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    res += a[0, i] * Addition(0, i).Det();
                else
                    res -= a[0, i] * Addition(0, i).Det();
            }
            return res;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n = 3;
            Poly[,] a = new Poly[n, n];
            a[0, 0] = new Poly("xy^2");
            a[0, 1] = new Poly("xy^2");
            a[0, 2] = new Poly("-1 - xy^2");
            a[1, 0] = new Poly("x^2y + xy^2");
            a[1, 1] = new Poly("x^2y + x");
            a[1, 2] = new Poly("x - y^2");
            a[2, 0] = new Poly("-y + x^2y");
            a[2, 1] = new Poly("-y^2");
            a[2, 2] = new Poly("y + xy");
            Matrix m = new Matrix(n, a);
            Console.WriteLine(m.Det().ToString());
        }
    }
}
