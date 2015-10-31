#include <iostream>

using namespace std;

void qSort(int left, int right, int arr[], int arr1[])
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
            swap(arr1[leftIndex], arr1[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }
    if (leftIndex < right)
    {
        qSort(leftIndex, right, arr, arr1);
    }
    if (rightIndex > left)
    {
        qSort(left, rightIndex, arr, arr1);
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n;
    cin >> n;
    int a[2000] = {};
    int d[2000] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> d[i];
    }
    qSort(0, n - 1, a, d);
    bool isCorrect = true;
    for (int i = 0; i < n; i++)
    {
        int finish = 180 + a[i] - 1;
        int count = 0;
        for (int j = i; j < n && a[j] <= finish; j++)
        {
            count += min(d[j], finish) - a[j] + 1;
        }
        if (count > 90)
        {
            isCorrect = false;
            break;
        }

    }
    if (isCorrect)
    {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}

