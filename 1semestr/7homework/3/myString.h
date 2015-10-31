#pragma once

struct String;

String *getNewString(char *newString);

int length(String *string);

String *clone(String *string);

char getChar(String *string, int index);

long long getHash(String *string);

void concat(String *string, String *stringToConcat);

int compare(String *string1, String *string2);

bool isEmpty(String *string);

String *substring(String *string, int start, int length);

char *stringToChar(String *string);

void deleteString(String *string);
