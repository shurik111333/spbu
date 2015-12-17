using System;
namespace Sortings
{
	public class InsertSorter
	{
		//public static TimeSpan TimeOfSort {get; private set;}
		
		/*private static void Swap(ref int[] sortArray, ref int pos1)
		{
			int temp = sortArray[pos1];
			sortArray[pos1] = sortArray[pos1 - 1];
			sortArray[pos1 - 1] = temp;
		}*/
		
		private static int[] SortPrefix(int[] sortArray,int position)
		{
			for (int i = position - 1; i > 0 && sortArray[i] < sortArray[i - 1]; i--)
			{
				Swap.Exchange(ref sortArray[i], ref sortArray[i - 1]);
			}
			return sortArray;
		}
		
		public static TimeSpan Sort (int[] sortArray)
		{
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }

			DateTime before = DateTime.Now;
            for (int i = 1; i < sortArray.Length; i++)
            {
                int currElement = sortArray[i];
                int j;
                for (j = i - 1; j >= 0 && sortArray[j] > currElement; j--)
                {
                    sortArray[j + 1] = sortArray[j];
                }
                sortArray[j + 1] = currElement;    
            }
           
            return DateTime.Now - before;
		}
	}
}
