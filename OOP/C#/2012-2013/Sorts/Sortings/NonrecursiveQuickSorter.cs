using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sortings
{
    public class NonrecursiveQuickSorter
    {
        private static void Swap(ref int number1, ref int number2)
        {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }

        public static TimeSpan Sort(int[] sortArray)
        {
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }
            DateTime before = DateTime.Now;
            if (sortArray.Length > 1)
            {
                Stack<int> stackLeft = new Stack<int>(), stackRight = new Stack<int>();
                stackLeft.Push(0);
                stackRight.Push(sortArray.Length - 1);
                int left, right, i, j, middle;
                while (stackLeft.Count > 0)
                {
                    left = stackLeft.Pop();
                    right = stackRight.Pop();
                    i = left;
                    j = right;
                    middle = sortArray[(left + right) / 2];
                    while (i <= j)
                    {
                        while (sortArray[i] < middle)
                        {
                            i++;
                        }
                        while (sortArray[j] > middle)
                        {
                            j--;
                        }
                        if (i <= j)
                        {
                            Swap(ref sortArray[i], ref sortArray[j]);
                            i++;
                            j--;
                        }
                    }
                    if (i < right)
                    {
                        stackLeft.Push(i);
                        stackRight.Push(right);
                    }
                    if (left < j)
                    {
                        stackLeft.Push(left);
                        stackRight.Push(j);
                    }
                }
            }
            return DateTime.Now - before;
        }
    }
}
