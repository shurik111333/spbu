#include "myString.h"

int min(int a, int b);

String::String()
{
    this->value = nullptr;
    this->len = 0;
}

String::String(char *newString)
{
    this->len = length(newString);
    value = new char[this->len + 1];
    for (int i = 0; i < this->len; i++)
    {
        value[i] = newString[i];
    }
    value[this->len] = '\0';
}

String::String(char *newString, int len)
{
    this->len = len;
    value = new char[this->len + 1];
    for (int i = 0; i < this->len; i++)
    {
        value[i] = newString[i];
    }
    value[this->len] = '\0';
}

String::String(const String &string)
{
    String *tmp = new String(string.value, string.len);
    this->value = tmp->value;
    this->len = tmp->len;
}

String::~String()
{
    delete[] this->value;
}

void String::skipEqual(const String &str1, const String &str2, int &index)
{
    while (index < min(str1.len, str2.len) && str1.value[index] == str2.value[index])
    {
        index++;
    }
}

bool String::operator ==(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->len, string.len) && this->len == string.len);

}

bool String::operator !=(const String &string)
{
    return !(*this == string);
}

bool String::operator <(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->len, string.len) && this->len < string.len) ||
           (index < min(this->len, string.len) && this->value[index] < string.value[index]);
}

bool String::operator >(const String &string)
{
    int index = 0;
    skipEqual(*this, string, index);
    return (index == min(this->len, string.len) && this->len > string.len) ||
           (index < min(this->len, string.len) && this->value[index] > string.value[index]);
}

String String::operator =(const String &string)
{
    if (this == &string)
        return *this;
    return String(string);
}

String String::operator =(char *string)
{
    return String(string);
}

std::ostream &operator <<(std::ostream &out, const String &string)
{
    if (!string.isEmpty())
        out << string.value;
    return out;
}

int String::length(char *string)
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
    return this == nullptr ? 0 : this->len;
}

/*String String::clone()
{
    return new String(this);
}*/

void String::append(String &string)
{
    int newLength = this->length() + string.length();
    char *newString = new char[newLength + 1];
    for (int i = 0; i < this->length(); i++)
    {
        newString[i] = this->value[i];
    }
    for (int i = 0; i < string.length(); i++)
    {
        newString[i + this->length()] = string.value[i];
    }
    newString[newLength] = '\0';
    delete[] this->value;
    this->value = newString;
    this->len = newLength;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

/*int String::compare(String *string1, String *string2)
{
    int currentIndex = 0;
    while (currentIndex < min(string1->length(), string2->length()) && string1->value[currentIndex] == string2->value[currentIndex])
    {
        currentIndex++;
    }
    if (currentIndex == min(string1->length(), string2->length()))
        return string1->length() - string2->length();
    else
        return string1->value[currentIndex] - string2->value[currentIndex];
}*/

bool String::isEmpty() const
{
    return this->length() == 0;
}

String String::substring(int start, int length) const
{
    int newLength = min(length, this->length() - start);
    char *substr = new char[newLength + 1];
    for (int i = start; i < start + newLength; i++)
    {
        substr[i - start] = this->value[i];
    }
    substr[newLength] = '\0';
    return String(substr, newLength);
}

char *String::toChar()
{
    char *result = new char[this->length() + 1];
    for (int i = 0; i < this->length(); i++)
    {
        result[i] = this->value[i];
    }
    result[this->length()] = '\0';
    return result;
}

/*void String::deleteString(String *string)
{
    delete[] string->value;
    delete string;
}*/
