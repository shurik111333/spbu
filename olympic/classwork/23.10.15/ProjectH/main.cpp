#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int p1 = 997;
const int mod1 = 1000000000 + 7;
const int p2 = 41;
const int mod2 = 1000000000 + 9;
const int mapSize = 300000;
char currLine[110005] = {};

int min(int a, int b)
{
    return a < b ? a : b;
}

struct String
{
    char *value;
    int length;
    int hash1;
    int hash2;

    String (String *string)
    {
        length = string->length;
        value = new char[length + 1];
        hash1 = string->hash1;
        hash2 = string->hash2;
        for (int i = 0; i < length; i++)
        {
            value[i] = string->value[i];
        }
        value[length] = '\0';
    }

    String (char *str, int length, int hash1, int hash2)
    {
        this->hash1 = hash1;
        this->hash2 = hash2;
        this->length = length;
        this->value = str;
    }
};

int compareStr(String *str1, String *str2)
{
    if (str1->hash1 == str2->hash1 && str1->hash2 == str2->hash2)
        return 0;
    int index = 0;
    while (index < min(str1->length, str2->length) && str1->value[index] == str2->value[index])
    {
        index++;
    }
    return str1->value[index] - str2->value[index];
}

int getHash(String *string)
{
    return string->hash1 + string->hash2;
}

struct BSTNode
{
    String *value;
    int height;
    int count;
    BSTNode *left;
    BSTNode *right;

    BSTNode(String *value)
    {
        this->value = value;
        height = count = 1;
        left = right = nullptr;
    }

    BSTNode(String *value, int count)
    {
        this->value = new String(value);
        height = 1;
        this->count = count;
        left = right = nullptr;
    }
};

struct BST
{
    BSTNode *root = nullptr;
};

BST **getNewBSTArray(int count)
{
   BST **result = new BST*[count];
   for (int i = 0; i < count; i++)
   {
       result[i] = new BST;
   }
   return result;
}

int find(BSTNode *&node, String *value, int count);

int addToBST(BST *tree, String *value, int count)
{
   return find(tree->root, value, count);
}

struct Hashmap
{
    BST **array;
    int size;
    int countElements;
    int maxChainIndex;
    int emptySpaces;
    double averageLengthOfChain;

    Hashmap(int size)
    {
        array = getNewBSTArray(size);
        this->size = emptySpaces = size;
        countElements = maxChainIndex = averageLengthOfChain = 0;
    }
};

Hashmap *map;

Hashmap *getNewHashmap(int size)
{
    return new Hashmap(size);
}

int addToMap(String *string, int count)
{
        int hash = string->hash1 + string->hash2;
        hash %= map->size;
        return addToBST(map->array[hash], string, count);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int find(BSTNode *&node, String *value, int count)
{
    BSTNode **currNode = &node;
    int cmp = 0;
    while (true)
    {
        if (*currNode == nullptr)
        {
            *currNode = new BSTNode(value, count);
            return count;
        }
        cmp = compareStr((*currNode)->value, value);
        if (cmp == 0)
        {
            (*currNode)->count += count;
            return (*currNode)->count;
        }
        if (cmp > 0)
            currNode = &(*currNode)->left;
        else
            currNode = &(*currNode)->right;
    }
}

/*String *getNewString(char *newString, int length, int hash1, int hash2)
{
    return new String(newString, length, hash1, hash2);
}*/


int main()
{
    FILE *input = fopen("incrementator.in", "r");
    ofstream fout("incrementator.out");
    fout.sync_with_stdio(false);
    map = getNewHashmap(mapSize);
    char c;
    while (true)
    {
        c = getc(input);
        if (feof(input))
            break;
        int index = 0;
        unsigned int hash1 = 0;
        unsigned int hash2 = 0;
        while (c != ' ')
        {
            currLine[index++] = c;
            hash1 = (hash1 * p1 + c);
            hash2 = (hash2 * p2 + c);
            c = getc(input);
        }
        currLine[index] = '\0';
        String *line = new String(currLine, index, hash1 % mod1, hash2 % mod2);
        int numb = 0;
        bool isMinus = false;
        c = getc(input);
        if (c == '-')
        {
            isMinus = true;
            c = getc(input);
        }
        while (isdigit(c))
        {
            numb = numb * 10 + c - '0';
            c = getc(input);
        }
        if (isMinus)
            numb = - numb;
        //addToMap(line, numb);
        fout << addToMap(line, numb) << "\n";
    }
    return 0;
}
