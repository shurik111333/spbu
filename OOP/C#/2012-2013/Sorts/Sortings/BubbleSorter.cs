using System;
namespace Sortings
{
	public class BubbleSorter
	{
		//public static TimeSpan TimeOfSort {get; private set;}
		
		public static TimeSpan Sort (int[] sortArray)
		{
			if (sortArray == null)
			{
				throw new ArgumentException("sortArray");
			}
            DateTime before = DateTime.Now;
			//int temp = 0;
			for (int i = 1; i < sortArray.Length; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (sortArray[j] > sortArray[i])
					{
						/*temp = sortArray[j];
						sortArray[j] = sortArray[j + 1];
						sortArray[j + 1] = temp;*/
                        Swap.Exchange(ref sortArray[j], ref sortArray[i]);
					}
				}
			}
			return DateTime.Now - before;
		}
	}
}
