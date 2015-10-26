#include <iostream>
#include <str.h>

using namespace std;

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
};

struct BST
{
    BSTNode *root = nullptr;
};

enum Action
{
    nothing,
    addAction,
    removeAction,
    getCountAction,
    findAction
};

enum PrintTreeType
{
    defaultOrder,
    ascendingOrder,
    descendingOrder
};

BST *getNewBST()
{
    return new BST;
}

BST **getNewBSTArray(int count)
{
   BST **result = new BST*[count];
   for (int i = 0; i < count; i++)
   {
       result[i] = new BST;
   }
   return result;
}

int getHeight(BSTNode *node)
{
    return node ? node->height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void updateHeight(BSTNode *node)
{
    if (node == nullptr)
        return;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}
int getBalance(BSTNode *node)
{
    return getHeight(node->left) - getHeight(node->right);
}

void leftRotation(BSTNode *&node)
{
    BSTNode *oldRight = node->right;
    node->right = oldRight->left;
    oldRight->left = node;
    node = oldRight;
    updateHeight(node->left);
    updateHeight(node);
}

void rightRotation(BSTNode *&node)
{
    BSTNode *oldLeft = node->left;
    node->left = oldLeft->right;
    oldLeft->right = node;
    node = oldLeft;
    updateHeight(node->right);
    updateHeight(node);
}

void balance(BSTNode *&node)
{
    if (node == nullptr)
        return;

    updateHeight(node);
    if (getBalance(node) == 2)
    {
        if (getBalance(node->left) < 0)
        {
            leftRotation(node->left);
        }
        rightRotation(node);
    }
    if (getBalance(node) == -2)
     {
         if (getBalance(node->right) > 0)
         {
             rightRotation(node->right);
         }
         leftRotation(node);
     }
}

BSTNode **getMin(BSTNode *&node)
{
    return (node->left == nullptr) ? &node : getMin(node->left);
}

BSTNode **getNextNode(BSTNode *&node)
{
    return getMin(node->right);
}

int find(BSTNode *&node, String *value, Action action);

bool removeNode(BSTNode *&node)
{
    if (node == nullptr)
        return false;

    if (!(node->left || node->right))
    {
        deleteString(node->value);
        delete node;
        node = nullptr;
        return true;
    }
    if (node->left == nullptr)
    {
        deleteString(node->value);
        node = node->right;
        return true;
    }
    if (node->right == nullptr)
    {
        deleteString(node->value);
        node = node->left;
        return true;
    }
    BSTNode **tmp = getNextNode(node);
    deleteString(node->value);
    node->value = clone((*tmp)->value);
    node->count = (*tmp)->count;
    find(node->right, (*tmp)->value, removeAction);
    return true;
}

bool addNode(BSTNode *&node, String *value)
{
    if (node != nullptr)
    {
        node->count++;
        return false;
    }
    node = new BSTNode(value);
    return true;
}

int getCount(BSTNode *node)
{
    return node == nullptr ? 0 : node->count;
}

int doAction(BSTNode *&node, String *value, Action action)
{
    switch (action)
    {
    case addAction:
    {
        return addNode(node, value);
    }
    case removeAction:
    {
        return removeNode(node);
    }
    case getCountAction:
    {
        return getCount(node);
    }
    case findAction:
    {
        return node != nullptr;
    }
    default:
    {
        return -1;
    }
    }
}

int find(BSTNode *&node, String *value, Action action = findAction)
{
    int result = 0;
    if (node == nullptr || (*node->value) == (*value))
    //if (node == nullptr || compare(node->value, value) == 0)
    {
        result = doAction(node, value, action);
    }
    else
    {
        if ((*node->value) > (*value))
        //if (compare(node->value, value) > 0)
        {
            result = find(node->left, value, action);
        }
        else
        {
            result = find(node->right, value, action);
        }
    }
    balance(node);
    return result;
}

int getCount(BST *tree, String *value)
{
    return find(tree->root, value, getCountAction);
}

bool remove(BST *tree, String *value)
{
    return find(tree->root, value, removeAction);
}

bool add(BST *tree, String *value)
{
    return find(tree->root, value, addAction);
}

bool isExist(BST *tree, String *value)
{
    return find(tree->root, value);
}

void printTreeInAscendingOrder(BSTNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printTreeInAscendingOrder(node->left);
    cout << node->value << " ";
    printTreeInAscendingOrder(node->right);
}

void printTreeInDescendingOrder(BSTNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printTreeInDescendingOrder(node->right);
    cout << node->value << " ";
    printTreeInDescendingOrder(node->left);
}

void printTree(BSTNode *node)
{
    if (node == nullptr)
    {
        cout << "null ";
        return;
    }
    cout << "( " << node->value << " ";
    printTree(node->left);
    printTree(node->right);
    cout << ") ";

}

void printTree(BST *tree, int modifier)
{
    switch ((PrintTreeType)modifier)
    {
    case defaultOrder:
    {
        printTree(tree->root);
        break;
    }
    case ascendingOrder:
    {
        printTreeInAscendingOrder(tree->root);
        break;
    }
    case descendingOrder:
        printTreeInDescendingOrder(tree->root);
        break;
    }
    cout << endl;
}

void removeTree(BST *tree)
{
    while (tree->root)
    {
        find(tree->root, tree->root->value, removeAction);
    }
    delete tree;
}
