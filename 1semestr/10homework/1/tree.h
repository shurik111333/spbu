#pragma once

struct Tree;

Tree *getNewTree(char value, int priority);

int getPriority(const Tree *tree);

Tree *merge(Tree *treeLeft, Tree *treeRight);

char **getCodes(Tree *tree);

void deleteTree(Tree *tree);
