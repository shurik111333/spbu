using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

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

        public Poly Det(int q, Poly prev, string sign)
        {
            if (Program.r.Count == q)
                Program.r.Add(new StringBuilder());
            /*if (Program.r.Count == q + 1)
                Program.r.Add(new StringBuilder());*/
            if (n == 1)
            {
                //Poly result = a[0, 0] * a[1, 1] - a[0, 1] * a[1, 0];
                //Program.result[q].Add(new Element(result, new Matrix(0)));
                Program.r[q].Append(sign + "(" + (prev * a[0, 0]).ToString() + ")");
                /*if (Program.r.Count == q + 1)
                    Program.r.Add(new StringBuilder());
                Program.r[q + 1].Append(sign + "(" + (prev * result).ToString() + ")");*/
                return a[0, 0];
            }
            Poly res = new Poly();
            if (sign != "")
                for (int i = q; i < Program.r.Count; i++)
                    Program.r[i].Append(sign + "(");
            //Program.r[q].Append("(");
            for (int i = 0; i < n; i++)
            {
                Matrix add = Addition(0, i);
                string s = "";
                if (i % 2 == 0)
                {
                    if (i != 0)
                    {
                        s = " + ";
                    }
                    res += a[0, i] * add.Det(q + 1, prev * a[0, i], s);
                }
                else
                {
                    s = " - ";
                    res -= a[0, i] * add.Det(q + 1, prev * a[0, i], s);
                }
                Program.r[q].Append(s + "(" + (a[0, i] * prev).ToString() + ") * " + add.ToString());
            }
            if (sign != "")
                Program.r[q].Append(")");
            return res;
        }

        public override string ToString()
        {
            if (n == 1)
                return "(" + a[0, 0].ToString() + ")";
            StringBuilder result = new StringBuilder(@"\begin{vmatrix} " + a[0, 0].ToString());
            for (int i = 1; i < n; i++)
            {
                result.Append(" & " + a[0, i]);
            }
            for (int i = 1; i < n; i++)
            {
                result.Append(@" \\ " + a[i, 0].ToString());
                for (int j = 1; j < n; j++)
                {
                    result.Append(" & " + a[i, j].ToString());
                }
            }
            return result.Append(@" \end{vmatrix}").ToString();
        }
    }

    class Program
    {
        private static string resFile = "res.txt";
        public static List<StringBuilder> r = new List<StringBuilder>();

        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name.");
            Console.WriteLine("On first line file must contains n - size of determinant.");
            Console.WriteLine("On next n * n lines print elements of matrix in order left-right, top-bottom(e.x. print elements of first line of matrix, then second line etc.)");
            Console.WriteLine("Result was in " + resFile + ".");
            string file = Console.ReadLine();
            StreamReader f = new StreamReader(file);
            int n = int.Parse(f.ReadLine());
            Poly[,] a = new Poly[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i, j] = new Poly(f.ReadLine());
                }
            }
            f.Close();
            Matrix m = new Matrix(n, a);
            StreamWriter w = new StreamWriter(resFile);
            r.Add(new StringBuilder("$" + m.ToString()));
            string res1 = m.Det(1, new Poly("1"), "").ToString();
            r.Add(new StringBuilder(res1 + "$"));
            w.WriteLine(string.Join<StringBuilder>(" =\n ", r));
            w.Close();
        }
    }
}
