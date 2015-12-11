#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct DTree
{
    int y;
    int value;
    int size;
    int min;
    DTree *left;
    DTree *right;

    DTree(int value)
        :y(rand()), value(value), size(1), min(value), left(nullptr), right(nullptr)
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
    root->min = root->value;
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
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");
    int n = 0;
    fin >> n;
    DTree *tree = nullptr;
    for (int i = 0; i < n; i++)
    {
        char c;
        int a, b;
        fin >> c >> a >> b;
        if (c == '+')
        {
            DTree *left;
            DTree *right;
            split(tree, a, left, right);
            tree = merge(left, merge(new DTree(b), right));
        }
        else
        {
            DTree *left;
            DTree *median;
            DTree *right;
            split(tree, b, median, right);
            split(median, a - 1, left, median);
            fout << median->min << "\n";
            tree = merge(left, merge(median, right));
        }
    }
    return 0;
}
