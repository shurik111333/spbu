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
};

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

int min(int a, int b)
{
    return a < b ? a : b;
}

int compare(String *string1, String *string2)
{
    int currentIndex = 0;
    while (currentIndex < min(length(string1), length(string2)) && string1->value[currentIndex] == string2->value[currentIndex])
    {
        currentIndex++;
    }
    if (currentIndex == min(length(string1), length(string2)))
        return length(string1) - length(string2);
    else
        return string1->value[currentIndex] - string2->value[currentIndex];
}

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
