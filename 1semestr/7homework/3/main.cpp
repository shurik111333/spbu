#include <iostream>
#include <hashmap.h>
#include <str.h>
#include <cstring>

using namespace std;

const int maxLen = 256;

void deleteNewLineSymbol(char *string)
{
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }
}

FILE *getFileToRead()
{
    char fileName[maxLen] = {};
    fgets(fileName, maxLen - 1, stdin);
    deleteNewLineSymbol(fileName);
    FILE *fileToRead = fopen(fileName, "r");
    while (fileToRead == nullptr)
    {
        cout << "Не удалось открыть файл. Попробуйте снова" << endl;
        fgets(fileName, maxLen - 1, stdin);
        deleteNewLineSymbol(fileName);
        fileToRead = fopen(fileName, "r");
    }
    return fileToRead;
}

String *getNextWord(FILE *file)
{
    char currentChar = 0;
    while (!feof(file) && !isalpha(currentChar))
    {
        currentChar = getc(file);
    }
    if (feof(file))
        return nullptr;
    char *newWord = new char[maxLen];
    //newWord[0] = currentChar;
    int length = 0;
    while (isalpha(currentChar) && !feof(file))
    {
        newWord[length] = currentChar;
        length++;
        currentChar = getc(file);
    }
    newWord[length] = '\0';
    String *word = getNewString(newWord);
    delete newWord;
    return word;
}

int main()
{
    setlocale(LC_ALL, "rus");
    FILE *fileToRead = getFileToRead();
    String *nextWord = getNextWord(fileToRead);
    Hashmap *map = getNewHashmap(100);
    while (nextWord)
    {
        addToMap(map, nextWord);
        nextWord = getNextWord(fileToRead);
    }
    return 0;
}

