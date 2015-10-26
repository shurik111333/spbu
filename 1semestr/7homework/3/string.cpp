int min(int a, int b)
{
    return a < b ? a : b;
}

struct String
{
    char *value;
    int length;

    String (char *newString, int length)
    {
        this->length = length;
        value = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            value[i] = newString[i];
        }
        value[length] = '\0';
    }

    void compareStrings(const String &string, int &index)
    {
        while (index < min(this->length, string.length) && this->value[index] == string.value[index])
        {
            index++;
        }
    }

    bool operator == (const String &string)
    {
        int index = 0;
        compareStrings(string, index);
        return (index == min(this->length, string.length) && this->length == string.length);

    }

    bool operator < (const String &string)
    {
        int index = 0;
        compareStrings(string, index);
        return (index == min(this->length, string.length) && this->length < string.length) ||
               (index < min(this->length, string.length) && this->value[index] < string.value[index]);
    }

    bool operator > (const String &string)
    {
        int index = 0;
        compareStrings(string, index);
        return (index == min(this->length, string.length) && this->length > string.length) ||
               (index > min(this->length, string.length) && this->value[index] > string.value[index]);
    }
};

/*bool abc(String *str1, String *str2)
{
    return *str1 == *str2;
}

bool abc1(String *str1, String *str2)
{
    return *str1 > *str2;
}*/

int length(char *string)
{
    int result = 0;
    while (string[result] != '\0')
    {
        result++;
    }
    return result;
}

int length(String *string)
{
    return string == nullptr ? 0 : string->length;
}

char getChar(String *string, int index)
{
    return index < length(string) ? string->value[index] : '\0';
}

String *getNewString(char *newString)
{
    return new String(newString, length(newString));
}

String *clone(String *string)
{
    return new String(string->value, length(string));
}

void concat(String *string, String *stringToConcat)
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
    delete string->value;
    string->value = newString;
}


/*int compare(String *string1, String *string2)
{
    if (*string1 == *string2)
        return 0;
    else
        return *string1 > *string2 ? 1 : -1;
}*/

bool isEmpty(String *string)
{
    return length(string) == 0;
}

String *substring(String *string, int start, int length)
{
    char *substr = new char[length + 1];
    for (int i = start; i < start + length; i++)
    {
        substr[i - start] = string->value[i];
    }
    substr[length] = '\0';
    return new String(substr, length);
}

const int p = 53;

unsigned long long getHash(String *string)
{
    unsigned long long result = string->value[0];
    for (int i = 1; i < length(string); i++)
    {
        result = result * p + string->value[i];
    }
    return result;
}

char *stringToChar(String *string)
{
    char *result = new char[length(string) + 1];
    for (int i = 0; i < length(string); i++)
    {
        result[i] = string->value[i];
    }
    result[length(string)] = '\0';
    return result;
}

void deleteString(String *string)
{
    delete string->value;
    delete string;
}
