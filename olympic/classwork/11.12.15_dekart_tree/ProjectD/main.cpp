#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct DTree
{
    int y;
    int value;
    int size;
    long long sum;
    bool reverse;
    DTree *left;
    DTree *right;

    DTree(int value)
        :y(rand()), value(value), size(1), sum(value), reverse(false), left(nullptr), right(nullptr)
    {}
};

void push(DTree *node)
{
    if (node == nullptr)
        return;
    if (node->reverse)
    {
        swap(node->left, node->right);
        if (node->left != nullptr)
            node->left->reverse = !node->left->reverse;
        if (node->right != nullptr)
            node->right->reverse = !node->right->reverse;
        node->reverse = false;
    }
}

int size(DTree *root)
{
    return root == nullptr ? 0 : root->size;
}

void update(DTree *root)
{
    push(root);
    if (root == nullptr)
        return;
    root->size = 1;
    root->sum = root->value;
    if (root->left != nullptr)
    {
        root->size += root->left->size;
        root->sum += root->left->sum;
    }
    if (root->right != nullptr)
    {
        root->size += root->right->size;
        root->sum += root->right->sum;
    }
}

DTree *merge(DTree *left, DTree *right)
{
    push(left);
    push(right);
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
    push(root);
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
    ifstream fin("reverse.in");
    ofstream fout("reverse.out");
    int n = 0, m = 0;
    fin >> n >> m;
    DTree *tree = nullptr;
    for (int i = 1; i <= n; i++)
    {
        int a;
        fin >> a;
        tree = merge(tree, new DTree(a));
    }
    for (int i = 0; i < m; i++)
    {
        int a = 0, l = 0, r = 0;
        fin >> a >> l >> r;
        DTree *left = nullptr;
        DTree *median = nullptr;
        DTree *right = nullptr;
        split(tree, r, median, right);
        split(median, l - 1, left, median);
        if (a == 0)
            fout << median->sum << "\n";
        else
        {
            median->reverse = !median->reverse;
            push(median);
        }
        tree = merge(left, merge(median, right));
    }
    return 0;
}

