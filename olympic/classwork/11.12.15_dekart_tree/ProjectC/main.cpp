#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct DTree
{
    int x;
    int y;
    //int value;
    int size;
    int min;
    DTree *left;
    DTree *right;

    DTree(int key)
        :x(key), y(rand()), size(1), min(key), left(nullptr), right(nullptr)
    {}
};

int size(DTree *root)
{
    return root == nullptr ? 0 : root->size;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void update(DTree *root)
{
    if (root == nullptr)
        return;
    root->size = 1;
    root->min = root->x;
    if (root->left != nullptr)
    {
        root->size += root->left->size;
        root->min = min(root->left->min, root->min);
    }
    if (root->right != nullptr)
    {
        root->size += root->right->size;
        root->min = min(root->right->min, root->min);
    }
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

void splitCount(DTree *root, int k, DTree *&left, DTree *&right)
{
    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    if (k < (1 + size(root->left)))
    {
        right = root;
        splitCount(root->left, k, left, root->left);
    }
    else
    {
        left = root;
        splitCount(root->right, k - (1 + size(root->left)), root->right, right);
    }
    update(root);
}

void split(DTree *root, int x, DTree *&left, DTree *&right)
{
    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    if (x > root->x)
    {
        right = root;
        split(root->left, x, left, root->left);
    }
    else
    {
        left = root;
        split(root->right, x, root->right, right);
    }
    update(root);
}

int main()
{
    ifstream fin("kthmax.in");
    ofstream fout("kthmax.out");
    int n = 0;
    fin >> n;
    DTree *tree = nullptr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        if (a == 1)
        {
            DTree *left;
            DTree *right;
            split(tree, b, left, right);
            tree = merge(left, merge(new DTree(b), right));
            continue;
        }
        if (a == 0)
        {
            DTree *left;
            DTree *right;
            splitCount(tree, b, left, right);
            fout << left->min << "\n";
            tree = merge(left, right);
            continue;
        }
        DTree *left;
        DTree *median;
        DTree *right;
        split(tree, b, left, right);
        split(left, b + 1, left, median);
        tree = merge(left, right);
    }
    return 0;
}
