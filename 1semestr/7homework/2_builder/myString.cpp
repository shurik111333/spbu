#include "myString.h"
#include <cstring>

int min(int a, int b);

char *String::initValue(const char *string)
{
    char *value = new char[capacity];
    for (int i = 0; i < capacity; i++)
    {
        if (i < len)
            value[i] = string[i];
        else
            value[i] = '\0';
    }
    return value;
}

String::String()
    :len(0), capacity(0), value(nullptr)
{}

String::String(const String &string)
    :len(string.length()), capacity(string.capacity), value(initValue(string.value))
{}

String::String(const char *newString)
    :len(length(newString)), capacity(len * 2 + 1), value(initValue(newString))
{}

String::String (const char *newString, int capacity)
    :len(length(newString)), capacity(len < capacity ? capacity : len + 1), value(initValue(newString))
{}

/*String::String (char *newString, int capacity)
    :len(capacity), value(newString)
{}*/

String::~String()
{
    delete[] this->value;
}

void String::skipEqual(const String &str1, const String &str2, int &index)
{
    while (index < min(str1.length(), str2.length()) && str1.value[index] == str2.value[index])
    {
        index++;
    }
}

bool String::operator ==(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->length(), string.length()) && this->length() == string.length());
}

bool String::operator !=(const String &string)
{
    return !(*this == string);
}

bool String::operator <(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->length(), string.length()) && this->length() < string.length()) ||
           (index < min(this->length(), string.length()) && this->value[index] < string.value[index]);
}

bool String::operator >(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->length(), string.length()) && this->length() > string.length()) ||
           (index < min(this->length(), string.length()) && this->value[index] > string.value[index]);
}

char String::operator [](int index)
{
    return this->value[index];
}

std::ostream &operator <<(std::ostream &out, const String &string)
{
    out << string.value;
    return out;
}

int String::length(const char *string)
{
    int result = 0;
    while (string[result] != '\0')
    {
        result++;
    }
    return result;
}

int String::length() const
{
    return this->len;
}

bool String::empty() const
{
    return this->length() == 0;
}

/*String *getNewString(const char *newString)
{
    return new String(newString);
}*/

String String::clone()
{
    return String(*this);
}

/*String *concat(String *string, const String *stringToConcat)
{
    int newLength = length(string) + length(stringToConcat);
    char *newString = new char[newLength + 1];
    for (int i = 0; i < length(string); i++)
    {
        newString[i] = string->value[i];
    }
    for (int i = 0; i < length(stringToConcat); i++)
    {
        newString[i + length(string)] = stringToConcat->value[i];
    }
    newString[newLength] = '\0';
    delete string;
    string = new String(newString, newLength);
    return string;
}*/

int min(int a, int b)
{
    return a < b ? a : b;
}

/*bool isEmpty(const String *string)
{
    return length(string) == 0;
}*/

String String::substr(int start, int length)
{
    String result = String();
    result.len = min(length, this->length() - start);
    result.capacity = result.len * 2;
    result.value = new char[result.capacity];
    for (int i = 0; i < result.capacity; i++)
    {
        if (i + start < this->length())
            result.value[i] = this->value[i + start];
        else
            result.value[i] = '\0';
    }
    return result;
}

char *String::toChar() const
{
    char *result = new char[this->length() + 1];
    for (int i = 0; i < this->length(); i++)
    {
        result[i] = this->value[i];
    }
    result[this->length()] = '\0';
    return result;
}
