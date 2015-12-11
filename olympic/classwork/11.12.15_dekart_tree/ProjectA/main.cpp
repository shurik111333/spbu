#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct DTree
{
    int y;
    int value;
    int size;
    DTree *left;
    DTree *right;

    DTree(int value)
        :y(rand()), value(value), size(1), left(nullptr), right(nullptr)
    {}
};

int size(DTree *root)
{
    return root == nullptr ? 0 : root->size;
}

void update(DTree *root)
{
    if (root == nullptr)
        return;
    root->size = 1;
    root->size += (root->left == nullptr ? 0 : root->left->size);
    root->size += (root->right == nullptr ? 0 : root->right->size);
}

DTree *merge(DTree *left, DTree *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    if (left->y > right->y)
    {
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

void split(DTree *root, int k, DTree *&left, DTree *&right)
{
    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    if (k < size(root->left) + 1)
    {
        right = root;
        split(root->left, k, left, root->left);
    }
    else
    {
        left = root;
        split(root->right, k - (1 + size(root->left)), root->right, right);
    }
    update(root);
}

int main()
{
    ifstream fin("movetofront.in");
    ofstream fout("movetofront.out");
    int n = 0, m = 0;
    fin >> n >> m;
    DTree *tree = new DTree(1);
    for (int i = 2; i <= n; i++)
    {
        tree = merge(tree, new DTree(i));
    }
    for (int i = 0; i < m; i++)
    {
        int l = 0, r = 0;
        fin >> l >> r;
        DTree *treeLeft;
        DTree *treeMed;
        DTree *treeRight;
        split(tree, r, treeMed, treeRight);
        split(treeMed, l - 1, treeLeft, treeMed);
        tree = merge(treeMed, merge(treeLeft, treeRight));
    }
    while (tree != nullptr)
    {
        DTree *left;
        split(tree, 1, left, tree);
        fout << left->value << " ";
    }
    return 0;
}

