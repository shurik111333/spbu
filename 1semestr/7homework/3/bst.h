#pragma once
#include <str.h>

struct BST;

BST *getNewBST();

BST **getNewBSTArray(int count);

bool add(BST *tree, String *value);

bool isExist(BST *tree, String *value);

bool remove(BST *tree, String *value);

bool printTree(BST *tree, int modifier);

void removeTree(BST *tree);
