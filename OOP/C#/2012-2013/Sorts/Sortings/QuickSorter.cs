using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sortings
{
    public class QuickSorter
    {
        private static void Swap(ref int number1, ref int number2)
        {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }


        private static void QSort(int left, int right, int[] sortArray)
        {
            int i = left;
            int j = right;
            int middle = sortArray[(left + right) / 2];
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
                QSort(i, right, sortArray);
            }
            if (j > left)
            {
                QSort(left, j, sortArray);
            }
        }


        public static TimeSpan Sort(int[] sortArray)
        {
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }
            DateTime begin = DateTime.Now;
            QSort(0, sortArray.Length - 1, sortArray);
            return DateTime.Now - begin;
        }
    }
}
