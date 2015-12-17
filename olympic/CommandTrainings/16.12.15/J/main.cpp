#include <iostream>
#include <string>
#include <fstream>

using namespace std;

pair<string, int> tempArray[55000] = {};

void Merge(int left, int middle, int right, pair<string, int> sortArray[], int ind)
{
	int indexLeft = left, indexRight = middle, indexResult = left;
	while (indexLeft < middle && indexRight < right)
	{
		if (sortArray[indexLeft].first[ind] <= sortArray[indexRight].first[ind])
		{
			tempArray[indexResult] = sortArray[indexLeft];
			indexLeft++;
			indexResult++;
		}
		else
		{
			tempArray[indexResult] = sortArray[indexRight];
			indexRight++;
			indexResult++;
		}
	}
	for (int i = indexLeft; i < middle; i++)
	{
		tempArray[indexResult] = sortArray[i];
		indexResult++;
	}
	for (int i = indexRight; i < right; i++)
	{
		tempArray[indexResult] = sortArray[i];
		indexResult++;
	}
	for (int i = left; i < right; i++)
	{
		sortArray[i] = tempArray[i];
	}
}

void Segmentation(int left, int right, pair<string, int> sortArray[], int ind)
{
	if (right - left > 1)
	{
		int middle = (left + right) / 2;
		Segmentation(left, middle, sortArray, ind);
		Segmentation(middle, right, sortArray, ind);
		Merge(left, middle, right, sortArray, ind);
	}
}

void qsort(int left, int right, int a[])
{
	int l = left;
	int r = right;
	int m = a[(left + right) / 2];
	while (l <= r)
	{
		while (a[l] < m)
			l++;
		while (a[r] > m)
			r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (l < right)
		qsort(l, right, a);
	if (left < r)
		qsort(left, r, a);
}

pair<string, int> a[55000] = {};
int ans[55000] = {};
int p[10] = {};

void next(int p[], int k)
{
	int i = k - 1;
	while (i > 0 && p[i] < p[i - 1])
		i--;
	if (i == 0)
	{
		p[0] = 0;
		return;
	}
	int min1 = i;
	for (int j = i + 1; j < k; j++)
	{
		if (p[j] > p[i - 1] && p[j] < p[min1])
			min1 = j;
	}
	swap(p[i - 1], p[min1]);
	qsort(i, k - 1, p);
}

int count(string s1, string s2, int k)
{
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		if (s1[i] != s2[i])
			res++;
	}
	return res;
}

pair<int, int> answer[55000] = {};

int main()
{
	ifstream fin("similar.in");
	ofstream fout("similar.out");
	int n, k;
	fin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		fin >> a[i].first;
		a[i].second = i;
		answer[i].first = 100;
	}
	for (int i = 1; i <= k; i++)
		p[i - 1] = i;
	//while (p[0] != 0)
	{
		for (int i = 0; i < k; i++)
		{
			Segmentation(0, n, a, p[i] - 1);
			if (count(a[0].first, a[1].first, k) < answer[a[0].second].first)
			{
				answer[a[0].second].first = count(a[0].first, a[1].first, k);
				answer[a[0].second].second = a[1].second;
			}
			for (int i = 1; i < n; i++)
			{
				if (i < n - 1)
				{
					if (count(a[i].first, a[i + 1].first, k) < answer[a[i].second].first)
					{
						answer[a[i].second].first = count(a[i].first, a[i + 1].first, k);
						answer[a[i].second].second = a[i + 1].second;
					}
				}
				if (count(a[i].first, a[i - 1].first, k) < answer[a[i].second].first)
				{
					answer[a[i].second].first = count(a[i].first, a[i - 1].first, k);
					answer[a[i].second].second = a[i - 1].second;
				}
			}
		}

		//next(p, k);
	}
	for (int i = 0; i < k; i++)
	{
		Segmentation(0, n, a, p[n - i - 1] - 1);
		if (count(a[0].first, a[1].first, k) < answer[a[0].second].first)
		{
			answer[a[0].second].first = count(a[0].first, a[1].first, k);
			answer[a[0].second].second = a[1].second;
		}
		for (int i = 1; i < n; i++)
		{
			if (i < n - 1)
			{
				if (count(a[i].first, a[i + 1].first, k) < answer[a[i].second].first)
				{
					answer[a[i].second].first = count(a[i].first, a[i + 1].first, k);
					answer[a[i].second].second = a[i + 1].second;
				}
			}
			if (count(a[i].first, a[i - 1].first, k) < answer[a[i].second].first)
			{
				answer[a[i].second].first = count(a[i].first, a[i - 1].first, k);
				answer[a[i].second].second = a[i - 1].second;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		fout << answer[i].first << " " << answer[i].second + 1 << "\n";
	}
	return 0;
}

