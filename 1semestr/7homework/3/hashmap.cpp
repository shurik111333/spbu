#include <bst.h>
#include <str.h>

struct Hashmap
{
    BST **array;
    int size;
    int countElements;

    Hashmap(int size)
    {
        array = getNewBSTArray(size);
        this->size = size;
        countElements = 0;
    }
};

const int minSize = 100;

Hashmap *getNewHashmap(int size = minSize)
{
    return new Hashmap(size);
}

void addToMap(Hashmap *map, String *string)
{
    unsigned long long hash = getHash(string);
    hash %= map->size;
    if (add(map->array[hash], string))
        map->countElements++;
    return;
}

bool findInMap(Hashmap *map, String *string)
{
    long long hash = getHash(string) % map->size;
    return isExist(map->array[hash], string);
}
