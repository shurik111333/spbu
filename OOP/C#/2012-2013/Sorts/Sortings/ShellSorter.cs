using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sortings
{
    public class ShellSorter
    {
        //public static TimeSpan TimeOfSort { get; private set; }

        /*private static void Swap(ref int[] sortArray, ref int pos1)
        {
            int temp = sortArray[pos1];
            sortArray[pos1] = sortArray[pos1 - 1];
            sortArray[pos1 - 1] = temp;
        }


        private static int[] SortPrefix(int[] sortArray, int position)
        {
            for (int i = position - 1; i > 0 && sortArray[i] < sortArray[i - 1]; i--)
            {
                Swap(ref sortArray, ref i);
            }
            return sortArray;
        }*/


        private static int Power(int number, int degree)
        {
            int[] path = new int[degree + 1];
            int result = 1;
            int i = degree;
            while (i > 0)
            {
                path[i] = 1;
                if (i % 2 == 0)
                {
                    i /= 2;
                }
                else
                {
                    i--;
                }
            }
            i = 0;
            while (i < degree)
            {
                if (path[i + 1] == 1)
                {
                    result *= number;
                    i++;
                }
                else
                {
                    result *= result;
                    i *= 2;
                }
            }
            return result;
        }


        private static void CountSteps(int number, ref int[] steps)
        {
            int i = 0, currStep = 1;
            while (currStep < number)
            {
                i++;
                if (i % 2 == 0)
                {
                    currStep = 9 * Power(2, i) - 9 * Power(2, i / 2) + 1;
                }
                else
                {
                    currStep = 8 * Power(2, i) - 6 * Power(2, (i + 1) / 2) + 1;
                }
            }
            steps = new int[i - 1];
            for (i = 0; i < steps.Length; i++)
            {
                if (i % 2 == 0)
                {
                    steps[i] = 9 * Power(2, i) - 9 * Power(2, i / 2) + 1;
                }
                else
                {
                    steps[i] = 8 * Power(2, i) - 6 * Power(2, (i + 1) / 2) + 1;
                }
            }
        }



        public static TimeSpan Sort(int[] sortArray)
        {
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }

            DateTime before = DateTime.Now;

            if (sortArray.Length > 0)
            {
                int[] steps = null;
            
                CountSteps(sortArray.Length, ref steps);
                
                int indexOfStep = steps.Length - 1;
                
                while (indexOfStep >= 0)
                {
                    int currStep = steps[indexOfStep];
                
                    for (int i = currStep; i < sortArray.Length; i++)
                    {
                        int currElement = sortArray[i];
                        int j;
                    
                        for (j = i - currStep; j >= 0 && sortArray[j] > currElement; j -= currStep)
                        {
                            sortArray[j + currStep] = sortArray[j];
                        }
                        sortArray[j + currStep] = currElement;
                    }
                    indexOfStep--;
                }
            }
            return DateTime.Now - before;
        }

    }
}
