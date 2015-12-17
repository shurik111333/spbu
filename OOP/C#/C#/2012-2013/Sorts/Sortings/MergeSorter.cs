using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sortings
{
    public class MergeSorter
    {
        private static int[] tempArray;
        private static void Merge(int left, int middle, int right, int[] sortArray)
        {
            int indexLeft = left, indexRight = middle, indexResult = left;
            while (indexLeft < middle && indexRight < right)
            {
                if (sortArray[indexLeft] < sortArray[indexRight])
                {
                    tempArray[indexResult] = sortArray[indexLeft];
                    indexLeft++;
                    indexResult++;
                }
                else
                {
                    tempArray[indexResult] = sortArray[indexRight];
                    indexRight++;
                    indexResult++;
                }
            }
            for (int i = indexLeft; i < middle; i++)
            {
                tempArray[indexResult] = sortArray[i];
                indexResult++;
            }
            for (int i = indexRight; i < right; i++)
            {
                tempArray[indexResult] = sortArray[i];
                indexResult++;
            }
            for (int i = left; i < right; i++)
            {
                sortArray[i] = tempArray[i];
            }
        }

        private static void Segmentation(int left, int right, int[] sortArray)
        {
            if (right - left > 1)
            {
                int middle = (left + right) / 2;
                Segmentation(left, middle, sortArray);
                Segmentation(middle, right, sortArray);
                Merge(left, middle, right, sortArray);
            }
        }

        public static TimeSpan Sort(int[] sortArray)
        {
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }
            DateTime begin = DateTime.Now;
            tempArray = new int[sortArray.Length];
            Segmentation(0, sortArray.Length, sortArray);
            return DateTime.Now - begin;
        }
    }
}
