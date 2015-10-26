#pragma once
#include <str.h>

struct Hashmap;

Hashmap *getNewHashmap(int size);

void addToMap(Hashmap *map, String *string);

bool findInMap(Hashmap *map, String *string);
