#include <limits.h>
#include <cstring>
#include "tree.h"

struct TreeNode
{
    char value;
    bool isLetter;
    int height;
    int code;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char value, bool isLetter)
        :value(value), isLetter(isLetter), height(1), code(0), left(nullptr), right(nullptr)
    {}
};

struct Tree
{
    int priority;
    TreeNode *root;
};

Tree *getNewTree(char value, int priority)
{
    return new Tree{priority, new TreeNode(value, true)};
}

int getPriority(const Tree *tree)
{
    return tree == nullptr ? 0 : tree->priority;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

Tree *merge(Tree *treeLeft, Tree *treeRight)
{
    Tree *tree = new Tree{treeLeft->priority + treeRight->priority, new TreeNode('\0', false)};
    tree->root->left = treeLeft->root;
    tree->root->right = treeRight->root;
    tree->root->right->code = 1;
    tree->root->height = max(tree->root->left->height, tree->root->right->height) + 1;
    delete treeLeft;
    delete treeRight;
    return tree;
}

void setCodes(TreeNode *node, char **codes, char *currentCode, int length)
{
    currentCode[length++] = node->code + '0';
    if (node->isLetter)
    {
        currentCode[length] = '\0';
        codes[node->value - CHAR_MIN] = new char[length];
        strcpy(codes[node->value - CHAR_MIN], currentCode);
        return;
    }
    setCodes(node->left, codes, currentCode, length);
    setCodes(node->right, codes, currentCode, length);
}

char **getCodes(Tree *tree)
{
    char **codes = new char*[CHAR_MAX - CHAR_MIN + 1];
    for (int i = 0; i < CHAR_MAX - CHAR_MIN + 1; i++)
    {
        codes[i] = nullptr;
    }
    char *currentCode = new char[tree->root->height];
    int length = 0;
    setCodes(tree->root->left, codes, currentCode, length);
    setCodes(tree->root->right, codes, currentCode, length);
    delete[] currentCode;
    return codes;
}

void deleteTree(TreeNode *node)
{
    if (node->left)
        deleteTree(node->left);
    if (node->right)
        deleteTree(node->right);
    delete node;
}

void deleteTree(Tree *tree)
{
    deleteTree(tree->root);
    delete tree;
}
