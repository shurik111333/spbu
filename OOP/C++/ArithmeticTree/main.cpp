#include <iostream>
#include <cstdio>
#include "tree.h"

using namespace std;

int main()
{
	FILE *file = fopen("file.txt", "r");
	Tree *tree = new Tree(file);
	tree->print(cout);
	cout << endl;
	cout << tree->Calc() << endl;
	return 0;
}

