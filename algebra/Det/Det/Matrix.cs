using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Det
{
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
            if (n == 1)
            {
                Program.r[q].Append(sign + "(" + (prev * a[0, 0]).ToString() + ")");
                return a[0, 0];
            }
            Poly res = new Poly();
            if (sign != "")
                for (int i = q; i < Program.r.Count; i++)
                    Program.r[i].Append(sign + "(");
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
}
