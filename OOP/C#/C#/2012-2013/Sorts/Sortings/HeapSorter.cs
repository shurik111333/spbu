using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sortings
{
    public class HeapSorter
    {
        private static int size = 0;
        //public static TimeSpan TimeOfSort { get; private set; }

        private static int LeftSon(int vertex)
        {
            return vertex * 2;
        }

        private static int RightSon(int vertex)
        {
            return vertex * 2 + 1;
        }

        private static void Heapify(ref int[] heap, int vertex)
        {
            int maxVertex;

            while (vertex > 0)
            {
                maxVertex = vertex;
                if (LeftSon(vertex) <= size && heap[(LeftSon(vertex)) - 1] > heap[vertex - 1])
                {
                    maxVertex = vertex * 2;
                }
                if (RightSon(vertex) <= size && heap[RightSon(vertex) - 1] > heap[maxVertex - 1])
                {
                    maxVertex = vertex * 2 + 1;
                }
                if (maxVertex != vertex)
                {
                    Swap.Exchange(ref heap[maxVertex - 1], ref heap[vertex - 1]);
                    vertex = maxVertex;
                }
                else
                {
                    vertex /= 2;
                }
            }
        }

        private static void BuildHeap(ref int[] heap)
        {
            for (int i = heap.Length; i > 0; i--)
            {
                Heapify(ref heap, i);
            }
        }

        public static TimeSpan Sort (int[] sortArray)
        {
            if (sortArray == null)
            {
                throw new ArgumentException("sortArray");
            }
            
            DateTime before = DateTime.Now;

            size = sortArray.Length;
            BuildHeap(ref sortArray);

            for (int i = sortArray.Length; i > 0; i--)
            {
                Swap.Exchange(ref sortArray[0], ref sortArray[size - 1]);
                size--;
                Heapify(ref sortArray, 1);
                
            }
            return DateTime.Now - before;
        }
    }
}
