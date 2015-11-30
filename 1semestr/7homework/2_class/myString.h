#pragma once

#include <ostream>

class String
{
private:
    char *value;
    int len;

    static void skipEqual(const String &str1, const String &str2, int &index);

    static int length(char *string);

public:

    String();

    String(char *newString);

    String(char *newString, int len);

    String(const String &string);

    ~String();

    bool operator ==(const String &string);

    bool operator !=(const String &string);

    bool operator <(const String &string);

    bool operator >(const String &string);

    String operator =(const String &string);

    String operator =(char *string);

    friend std::ostream &operator <<(std::ostream &out, const String &string);

    //static String *getNewString(char *newString);

    int length() const;

    //String clone();

    void append(String &string);

    //static int compare(String *string1, String *string2);

    bool isEmpty() const;

    String substring(int start, int length) const;

    char *toChar();
};


