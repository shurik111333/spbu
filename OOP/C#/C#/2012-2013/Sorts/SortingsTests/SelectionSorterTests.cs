using System;
using NUnit.Framework;

namespace SortingsTests
{
	[TestFixture()]
	public class SelectionSorterTests
	{
		[Test()]
		public void DecreasingArray ()
		{	
			int[] arrayForSort = {6, 5, 4, 3, 2, 1};
			int[] expResult = {1, 2, 3, 4, 5, 6};
			TimeSpan result = Sortings.SelectionSorter.Sort(arrayForSort);
			Assert.AreEqual(arrayForSort, expResult);
		}
		[Test()]
		public void SortArray ()
		{
			int[] arrayForSort = {1, 2, 3, 4, 5, 6};
			int[] expResult = {1, 2, 3, 4, 5, 6};
			TimeSpan result = Sortings.SelectionSorter.Sort(arrayForSort);
			Assert.AreEqual(arrayForSort, expResult);
		}
		[Test()]
		public void ZeroArray ()
		{
			int[] arrayForSort = {};
			int[] expResult = {};
			TimeSpan result = Sortings.SelectionSorter.Sort(arrayForSort);
			Assert.AreEqual(arrayForSort, expResult);
		}
		[Test()]
		public void NegativeArray ()
		{
			int[] arrayForSort = {-6, 5, -4, 3, 2, 1};
			int[] expResult = {-6, -4, 1, 2, 3, 5};
			TimeSpan result = Sortings.SelectionSorter.Sort(arrayForSort);
			Assert.AreEqual(arrayForSort, expResult);
		}
		[Test()]
		public void RandomArray ()
		{
			int[] arrayForSort = {45, -32, 2359, 0, -124, -583, 238, 2359};
			int[] expResult = {-583, -124, -32, 0, 45, 238, 2359, 2359};
			TimeSpan result = Sortings.SelectionSorter.Sort(arrayForSort);
			Assert.AreEqual(arrayForSort, expResult);
		}
        [Test()]
        [ExpectedException(typeof(ArgumentException))]
        public void NullArray()
        {
            int[] arrayForSort = null;
            int[] expResult = null;
            TimeSpan result = Sortings.NonrecursiveQuickSorter.Sort(arrayForSort);
        }

        [Test]
        public void RandomTests()
        {
            Random rand = new Random();
            int[] arrayForSort;
            for (int i = 0; i < 1000; i++)
            {
                int size = rand.Next(1, 100);
                arrayForSort = new int[size];
                for (int j = 0; j < size; j++)
                {
                    arrayForSort[j] = rand.Next(-100, 100);
                }
                Sortings.BubbleSorter.Sort(arrayForSort);
                for (int j = 1; j < size; j++)
                {
                    Assert.False(arrayForSort[j - 1] > arrayForSort[j]);
                }
            }
        }
	}
}
