using System;
namespace Sortings
{
	public class SelectionSorter
	{
		
		public static TimeSpan TimeOfSort {get; private set;}
		
		public static TimeSpan Sort (int[] sortArray)
		{
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }
			int indexOfMin = 0;
			int temp;
			DateTime before = DateTime.Now;
			for (int i = 0; i < sortArray.Length; i++)
			{
				indexOfMin = i;
				for (int j = i + 1; j < sortArray.Length; j++)
				{
					if (sortArray[j] < sortArray[indexOfMin])
					{
						indexOfMin = j;
					}
				}
				temp = sortArray[indexOfMin];
				sortArray[indexOfMin] = sortArray[i];
				sortArray[i] = temp;
			}
			return DateTime.Now - before;
		}
	}
}
