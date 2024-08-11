#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool solve(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->data != right->data)
    {
        return false;
    }
    return solve(left->left, right->right) && solve(left->right, right->left);
}
bool isSymmetric(struct Node *root)
{
    // Code here
    if (root == NULL)
    {
        return true;
    }
    return solve(root->left, root->right);
}