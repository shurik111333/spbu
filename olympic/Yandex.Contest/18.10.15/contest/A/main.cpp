#include <iostream>
#include <cmath>
using namespace std;

int countDel;
int del[100000] = {};

void qSort(int left, int right, int arr[])
{
    int leftIndex = left;
    int rightIndex = right;
    int comparingElement = arr[(left + right) / 2];
    while (leftIndex < rightIndex)
    {
        while (arr[leftIndex] < comparingElement)
        {
            leftIndex++;
        }
        while (arr[rightIndex] > comparingElement)
        {
            rightIndex--;
        }
        if (leftIndex <= rightIndex)
        {
            swap(arr[leftIndex], arr[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }
    if (leftIndex < right)
    {
        qSort(leftIndex, right, arr);
    }
    if (rightIndex > left)
    {
        qSort(left, rightIndex, arr);
    }
}

void dels(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            del[countDel] = i;
            countDel++;
            if (i != sqrt(n))
            {
                del[countDel] = n / i;
                countDel++;
            }
        }
    }
}

int main()
{
    long n;
    cin >> n;

    dels(n - 1);
    qSort(0, countDel - 1, del);
    for (int i = 0; i < countDel; i++)
    {
        cout << del[i] << " ";
    }
    return 0;
}

