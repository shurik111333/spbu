using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Det
{
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
