#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    int curr = root->data;
    if (curr < n1 && curr < n2)
    {
        return LCA(root->right, n1, n2);
    }
    if (curr > n1 && curr > n2)
    {
        return LCA(root->left, n1, n2);
    }

    return root;
}