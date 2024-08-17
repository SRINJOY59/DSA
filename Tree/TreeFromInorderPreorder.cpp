#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *solve(vector<int> &in, vector<int> &pre, int &index, int inStart, int inEnd)
{
    if (index >= pre.size() || inStart > inEnd)
    {
        return NULL;
    }

    int rootVal = pre[index];
    Node *root = new Node(rootVal);
    index++;

    int ind = -1;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (in[i] == rootVal)
        {
            ind = i;
            break;
        }
    }

    root->left = solve(in, pre, index, inStart, ind - 1);
    root->right = solve(in, pre, index, ind + 1, inEnd);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    vector<int> Inorder(in, in + n);
    vector<int> Preorder(pre, pre + n);
    int index = 0;
    return solve(Inorder, Preorder, index, 0, n - 1);
}