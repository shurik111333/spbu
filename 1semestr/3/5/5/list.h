#pragma once

struct List;

List *getNewList();

void addBack(List *list, int value);

void deleteNode(List *list, int value);

void setCurrentElementAtFirst(List *list);

int getCurrent(List *list);

int getNext(List *list);

int goToNext(List *list);

void clear(List *list);