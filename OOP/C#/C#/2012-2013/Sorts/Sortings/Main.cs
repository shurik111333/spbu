using System;

namespace Sortings
{
	class MainClass
	{
        const int minValue = -10000, maxValue = 10000;

		public static void Main (string[] args)
		{
			Console.WriteLine ("Введите количество элементов в массиве");
			string forRead = Console.ReadLine();
			int size;
			while(!(int.TryParse(forRead, out size)))
			{
				Console.WriteLine("Введите корректное количество элементов");
				forRead = Console.ReadLine();
			}
			int[] randArray = new int[size], arrayForSort = new int[size];
            Random rand = new Random();
			for (int i = 0; i < size; i++)
			{
			/*	Console.WriteLine("Введите {0}й элемент", i + 1);
				forRead = Console.ReadLine();
				while(!(int.TryParse(forRead, out arrayForSort[i])))
				{
					Console.WriteLine("Введите корректный элемент массива");
					forRead = Console.ReadLine();
				}*/
                randArray[i] = rand.Next(minValue, maxValue);
			}
            //Array.Copy(arrayForSort, size, randArray, size, size);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            //TimeSpan timeOfBubble = BubbleSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
			TimeSpan timeOfHeap = HeapSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfInsert = InsertSorter.Sort(arrayForSort);
            //Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            //TimeSpan timeOfMerge = MergeSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfNonrecursiveQuick = NonrecursiveQuickSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfQuick = QuickSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfSelection = SelectionSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfShell = ShellSorter.Sort(arrayForSort);
            Array.Copy(randArray, arrayForSort, arrayForSort.Length);
            TimeSpan timeOfMerge = MergeSorter.Sort(arrayForSort);
            for (int i = 0; i < size; i++)
			{
				Console.Write("{0} ", arrayForSort[i]);
			}
            Console.WriteLine();
            //Console.WriteLine("Время сортировки BubbleSort = {0}", timeOfBubble);
            Console.WriteLine("Время сортировки HeapSort = {0}", timeOfHeap);
            Console.WriteLine("Время сортировки InsertSort = {0}", timeOfInsert);
            Console.WriteLine("Время сортировки MergeSort = {0}", timeOfMerge);
            Console.WriteLine("Время сортировки NonrecursiveQuickSort = {0}", timeOfNonrecursiveQuick);
            Console.WriteLine("Время сортировки QuickSort = {0}", timeOfQuick);
            Console.WriteLine("Время сортировки SelectionSort = {0}", timeOfSelection);
            Console.WriteLine("Время сортировки ShellSort = {0}", timeOfShell);
            Console.ReadKey();
		}
	}
}