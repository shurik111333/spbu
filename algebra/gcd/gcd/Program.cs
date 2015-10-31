using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace gcd
{
    class Program
    {
        const string file = "file.txt";

        private static List<Pair> list = new List<Pair>();
        //private static Pair[] module = new Pair[100000000];
        private static string resultStr = "";

        struct Pair
        {
            public int a, b, c;

            public Pair(int a1, int b1, int c1)
            {
                a = a1;
                b = b1;
                c = c1;
            }
        }

        private static int gcd(int a, int b)
        {
            if (a % b == 0)
            {
                File.AppendAllText(file, a.ToString() + " = " + b.ToString() + " * " + (a / b).ToString() + "\n");
                return a;
            }
            //list.Add(new Pair(a, b));
            int currMod = a % b;
            int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
            foreach (Pair p in list)
            {
                if (p.c == a)
                {
                    a1 = p.a;
                    b1 = p.b;
                }
                if (p.c == b)
                {
                    a2 = p.a;
                    b2 = p.b;
                }
            }
            list.Add(new Pair(a1 - (a / b) * a2, b1 - (a / b) * b2, currMod));
            resultStr += string.Format("{0} = {7} - {8} * {9} = {1} * a + {2} * b - {9} * ({3} * a + {4} * b) = {5} * a + {6} * b\n", 
                currMod, a1, b1, a2, b2, list[list.Count - 1].a, list[list.Count - 1].b, a, b, a / b);
            File.AppendAllText(file, a.ToString() + " = " + b.ToString() + " * " + (a / b).ToString() + " + " + currMod + "\n");
            return gcd(b, currMod);
        }

        static void Main(string[] args)
        {
            int a = 51992935, b = 32126743;
            string line = Console.ReadLine();
            a = int.Parse(line.Split(' ')[0]);
            b = int.Parse(line.Split(' ')[1]);
            //int a = 4439, b = 1679;
            //module[a] = new Pair(1, 1);
            //module[b] = new Pair(1, 1);
            list.Add(new Pair(1, 0, Math.Abs(a)));
            list.Add(new Pair(0, 1, Math.Abs(b)));
            File.WriteAllText(file, string.Empty);
            resultStr += string.Format("a = {0}, b = {1}\n", Math.Abs(a), Math.Abs(b));
            gcd(Math.Abs(a), Math.Abs(b));
            File.AppendAllText(file, "\n");
            File.AppendAllText(file, resultStr);
        }
    }
}
