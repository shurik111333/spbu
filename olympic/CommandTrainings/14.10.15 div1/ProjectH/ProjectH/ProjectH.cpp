// ProjectH.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	
	ifstream fin("homo.in");
	fin.sync_with_stdio(false);
	ofstream fout("homo.out");
	fout.sync_with_stdio(false);
	int n = 0;
	fin >> n;
	map<int, int> elem;
	int count = 0;
	int countEqual = 0;
	int countDiff = 0;
	for (int i = 0; i < n; i++)
	{
		string command;
		int number = 0;
		fin >> command >> number;
		auto itMap = elem.find(number);
		if (command == "insert")
		{
			count++;
			
			if (itMap != elem.end())
			{
				if ((*itMap).second == 1)
				{
					countEqual++;
				}
				(*itMap).second++;
			}
			else
			{
				countDiff++;
				elem.insert(pair<int, int>(number, 1));
			}
		}
		else
		{
			if (itMap != elem.end())
			{
				count--;
				(*itMap).second--;
				if ((*itMap).second == 1)
					countEqual--;
				if ((*itMap).second == 0)
				{
					countDiff--;
					elem.erase(number);
				}
			}
		}
		if (countEqual > 0)
		{
			if (countDiff > 1)
			{
				fout << "both\n";
			}
			else
			{
				fout << "homo\n";
			}
		}
		else
		{
			if (countDiff > 1)
			{
				fout << "hetero\n";
			}
			else
				fout << "neither\n";
		}
	}
	return 0;
}

