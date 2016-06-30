#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <ctime>
#include "memory.h"

using namespace std;

size_t memorySize = 0;
size_t maxTime = 0;
size_t maxLength = 0;
size_t maxTicks = 0;

int rand(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

int main()
{
	cout << "This program emulates allocating memory.\n";
	cout << "Please enter size of memory, count of ticks, maximum time of life and length for allocated blocks.\n";
	cin >> memorySize >> maxTicks >> maxTime >> maxLength;
	cout << "Start allocating...\n";
	srand(time(0));
	Memory mem(memorySize);
	map<int, vector<byte*> > toRemove; // hashtable, keys - ticks, value - array of blocks, that must be removed at this tick
	for (int t = 0; t < maxTicks; t++)
	{
		for (int i = 0; i < toRemove[t].size(); i++)
		{
			mem.free(toRemove[t][i]);
		}
		toRemove.erase(t);

		int length = rand(1, maxLength);
		int time = rand(1, maxTime);
		byte *newBlock = mem.alloc(length);
		if (newBlock == NULL)
		{
			cout << "Fail on tick " << t << " with length " << length << endl;
			return 0;
		}
		toRemove[t + time].push_back(newBlock);
	}
	cout << "All memory was allocated correctly.";
	return 0;
}

