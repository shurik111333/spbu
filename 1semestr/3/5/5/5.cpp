// 5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� n, k" << endl;
	int n = 0;
	int k = 0;
	cin >> n >> k;
	List *soldiers = getNewList();
	for (int i = 1; i <= n; i++)
	{
		addBack(soldiers, i);
	}
	setCurrentElementAtFirst(soldiers);
	while (getNext(soldiers) != getCurrent(soldiers))
	{
		for (int i = 1; i < k; i++)
		{
			goToNext(soldiers);
		}
		deleteNode(soldiers, getCurrent(soldiers));
	}
	cout << "�����: " << getCurrent(soldiers) << endl;
	clear(soldiers);
    return 0;
}

