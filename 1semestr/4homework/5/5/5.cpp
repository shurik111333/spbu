// 5.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "list.h"

using namespace std;

void gen(int **a)
{

}

int main()
{
	int n = 0;
	int k = 0;
	cin >> n >> k;
	List *soldiers = getNewList();
	for (int i = n; i > 0; i--)
	{
		addNode(soldiers, i);
	}
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[k];
	}
	gen(a);
	/*ListNode *currSoldier = soldiers->first;
	while (soldiers->last->next != soldiers->last)
	{
		for (int i = 1; i < k; i++)
		{
			currSoldier = currSoldier->next;
		}
		ListNode *nextSoldier = currSoldier->next;
		deleteNode(soldiers, currSoldier->value);
		currSoldier = nextSoldier;
	}
	cout << soldiers->first->value << endl;*/
	system("pause");
	return 0;
}