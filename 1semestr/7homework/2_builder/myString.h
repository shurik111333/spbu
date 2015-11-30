#pragma once

#include <ostream>

class String
{
private:

    int len;
    int capacity;
    char *value;

    void skipEqual(const String &str1, const String &str2, int &index);

    char *initValue(const char *string);

    int length(const char *string);

    String();

public:

    String(const String &string);

    String(const char *newString);

    String(char *newString, int capcity);

    String(const char *newString, int capacity);

    ~String();

    bool operator ==(const String &string);

    bool operator !=(const String &string);

    bool operator <(const String &string);

    bool operator >(const String &string);

    char operator [](int index);

    friend std::ostream &operator <<(std::ostream &out, const String &string);

    int length() const;

    bool empty() const;

    String clone();

    String substr(int start, int length);

    char *toChar() const;
};

/*String *getNewString(const char *newString);

int length(const String *string);

String *clone(const String *string);

String *concat(String *string, const String *stringToConcat);

bool isEmpty(const String *string);

String *substring(const String *string, int start, int length);

char *stringToChar(const String *string);
*/
