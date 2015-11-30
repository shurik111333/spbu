#include "tree.h"
#include "heap.h"
#include <limits.h>

/*struct PriorityQueueNode
{
    Tree *value;
    int priority;
    PriorityQueueNode *next;

    PriorityQueueNode(Tree *value, int priority, PriorityQueueNode *next)
        :value(value), priority(priority), next(next)
    {}
};*/

struct PriorityQueue
{
    Heap *heap;
};

PriorityQueue *getNewQueue()
{
    return new PriorityQueue{getNewHeap()};
}

/*int size(PriorityQueue *queue)
{
    return queue == nullptr ? 0 : queue->size;
}

bool isEmpty(PriorityQueue *queue)
{
    return queue == nullptr || queue->size == 0;
}*/

/*void push(PriorityQueue *queue, Tree *value)
{
    PriorityQueueNode *newNode = new PriorityQueueNode(value, getPriority(value), nullptr);
    PriorityQueueNode *current = queue->tail;
    while (current->next->priority > newNode->priority)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    queue->size++;
}

Tree *pop(PriorityQueue *queue)
{
    if (isEmpty(queue))
        return nullptr;
    PriorityQueueNode *current = queue->tail;
    while (current->next->next != queue->head)
    {
        current = current->next;
    }
    Tree *node = current->next->value;
    delete current->next;
    current->next = queue->head;
    queue->size--;
    return node;
}

void deleteQueue(PriorityQueue *queue)
{
    while (!isEmpty(queue))
    {
        deleteTree(pop(queue));
    }
    delete queue->head;
    delete queue->tail;
    delete queue;
}*/

void push(PriorityQueue *queue, Tree *value)
{
    addToHeap(queue->heap, value);
}

int size(PriorityQueue *queue)
{
    return queue == nullptr ? 0 : size(queue->heap);
}

bool isEmpty(PriorityQueue *queue)
{
    return queue == nullptr || size(queue->heap) == 0;
}

Tree *pop(PriorityQueue *queue)
{
    return getMin(queue->heap);
}
