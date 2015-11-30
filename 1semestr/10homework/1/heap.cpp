#include "tree.h"

/*struct HeapNode
{
    int value;
    HeapNode *left;
    HeapNode *right;
    HeapNode *parent;
    HeapNode *previous;
    HeapNode *next;
    HeapNode(int value, HeapNode *left = nullptr, HeapNode *right = nullptr, HeapNode *parent = nullptr, HeapNode next = nullptr)
        :value(value), left(left), right(right), parent(parent), next(next)
    {}
};*/

const int defaultSize = 10;

struct Heap
{
    int size;
    int count;
    Tree **heap;
    /*HeapNode *root;
    HeapNode *end;*/

    Heap(int size = defaultSize)
        :size(size), count(0), heap(new Tree*[size])
    {}
};

Heap *getNewHeap()
{
    return new Heap();
}

Heap *getNewHeap(int size)
{
    return new Heap(size);
}

//void add(HeapNode *&node, )

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int rightSon(int vertex)
{
    return vertex * 2 + 1;
}

int leftSon(int vertex)
{
    return vertex * 2;
}

void heapify(int vertex, Heap *heap)
{
    while (vertex > 0)
    {
        int maxVertex = vertex;
        if (leftSon(vertex) <= heap->count && getPriority(heap->heap[leftSon(vertex) - 1]) < getPriority(heap->heap[maxVertex - 1]))
        {
            maxVertex = leftSon(vertex);
        }
        if (rightSon(vertex) <= heap->count && getPriority(heap->heap[rightSon(vertex) - 1]) < getPriority(heap->heap[maxVertex - 1]))
        {
            maxVertex = rightSon(vertex);
        }
        if (maxVertex != vertex)
        {
            swap(heap->heap[maxVertex - 1], heap->heap[vertex - 1]);
            vertex = maxVertex;
        }
        else
        {
            vertex /= 2;
        }
    }
}

void increaseHeap(Heap *heap)
{
    Tree **newHeap = new Tree*[heap->size * 2];
    for (int i = 0; i < heap->count; i++)
    {
        newHeap[i] = heap->heap[i];
    }
    delete heap->heap;
    heap->heap = newHeap;
}

void addToHeap(Heap *heap, Tree *value)
{
    if (heap->size == heap->count)
        increaseHeap(heap);
    heap->heap[heap->count++] = value;
    heapify(heap->count / 2, heap);
}

int size(Heap *heap)
{
    return heap == nullptr ? 0 : heap->count;
}

Tree *getMin(Heap *heap)
{
    swap(heap->heap[0], heap->heap[--heap->count]);
    heapify(1, heap);
    return heap->heap[heap->count];
}
