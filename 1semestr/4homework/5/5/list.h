#pragma once

struct List;

struct ListNode;

List *getNewList();

void addNode(List *list, int value);

void deleteNode(List *list, int value);

void deleteList(List *list);