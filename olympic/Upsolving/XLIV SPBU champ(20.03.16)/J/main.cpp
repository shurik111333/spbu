#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

struct Tree
{
	int x;
	int len;
	int lenn;
	int h;
	Tree *left;
	Tree *right;
	int spaces;
	int realH;
};

int getLen(int n)
{
	if (n == 0)
		return 1;
	int res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return res;
}

int getLen(Tree *root)
{
	return root == nullptr ? 0 : root->len;
}

int getH(Tree *root)
{
	return root == nullptr ? 0 : root->h;
}

void insert(Tree *&root, int v)
{
	if (root == nullptr)
	{
		root = new Tree{v, getLen(v), getLen(v), 1, nullptr, nullptr, 0, 0};
		return;
	}
	if (root->x > v)
		insert(root->left, v);
	else
		insert(root->right, v);
	root->h = max(getH(root->left), getH(root->right)) + 1;
	root->len = getLen(root->left) + getLen(root->right) + getLen(root->x);
}

int h;
//string *res;
int *out;
ifstream fin("xlrto2d.in");
ofstream fout("xlrto2d.out");

/*void push(int q, int d, int len)
{
	if (d > 0)
	{
		char *s = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			s[i] = ' ';
		}
		s[len] = '\0';
		for (int i = q; i < q + d; i++)
		{
			res[i].append(s);
		}
	}
	//delete s;
}*/

void print(Tree *root, int d)
{
	if (root == nullptr)
		return;
	print(root->left, d);
	root->spaces = d + getLen(root->left);
	print(root->right, root->spaces + root->lenn);
}

int main()
{
	Tree *root = nullptr;
	while (!fin.eof())
	{
		int x;
		x = -1;
		fin >> x;
		if (x == -1)
			break;
		insert(root, x);
	}
	//res = new string[root->h]
	h = root->h;
	out = new int[h];
	for (int i = 0; i < h; i++)
	{
		out[i] = 0;
	}
	print(root, 0);
	queue<Tree*> q;
	int currh = 0;
	q.push(root);
	root->realH = 0;
	while (!q.empty())
	{
		Tree *curr = q.front();
		q.pop();
		if (curr->realH != currh)
		{
			fout << "\n";
			currh = curr->realH;
		}
		for (int i = 0; i < curr->spaces - out[currh]; i++)
		{
			fout << ' ';
		}
		fout << curr->x;
		out[currh] = curr->spaces + curr->lenn;
		if (curr->left != nullptr)
		{
			curr->left->realH = currh + 1;
			q.push(curr->left);
		}
		if (curr->right != nullptr)
		{
			curr->right->realH = currh + 1;
			q.push(curr->right);
		}
	}
	fout << "\n";
	fin.close();
	fout.close();
	/*for (int i = 0; i < h; i++)
	{
		fout << res[i] << "\n";
	}*/
	//fout << res[h - 1];
	return 0;
}
