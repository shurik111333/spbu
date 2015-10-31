using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ProjectHcs
{
    class Program
    {
        const string fileIn = "homo.in", fileOut = "homo.out";
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(fileIn);
            int n = int.Parse(input[0]);
            Dictionary<int, int> elements = new Dictionary<int, int>();
            int countDiff = 0;
            int count = 0;
            int countEqual = 0;
            File.WriteAllText(fileOut, "");
            for (int i = 1; i <= n; i++)
            {
                string[] line = input[i].Split(' ');
                int a = int.Parse(line[1]);
                if (line[0] == "insert")
                {
                    count++;
                    if (elements.ContainsKey(a))
                    {
                        if (elements[a] == 1)
                            countEqual++;
                        elements[a]++;
                    }
                    else
                    {
                        countDiff++;
                        elements.Add(a, 1);
                    }
                }
                else
                {
                    if (elements.ContainsKey(a))
                    {
                        count--;
                        elements[a]--;
                        if (elements[a] == 1)
                        {
                            countEqual--;
                        }
                        if (elements[a] == 0)
                        {
                            countDiff--;
                            elements.Remove(a);
                        }
                    }
                }
                if (countEqual > 0)
                {
                    if (countDiff > 1)
                    {
                        File.AppendAllText(fileOut, "both\n");
                    }
                    else
                    {
                        File.AppendAllText(fileOut, "homo\n");
                    }
                }
                else
                {
                    if (countDiff > 1)
                    {
                        File.AppendAllText(fileOut, "hetero\n");
                    }
                    else
                        File.AppendAllText(fileOut, "neither\n");
                }
            }
        }
    }
}
