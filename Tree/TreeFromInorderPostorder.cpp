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

Node *solve(vector<int> Inorder, vector<int> postOrder, int instart, int inend, int &postIndex)
{
    if (Inorder.size() == 0 || instart > inend)
    {
        return NULL;
    }
    int rootVal = postOrder[postIndex];
    postIndex--;
    Node *root = new Node(rootVal);
    int ind = -1;
    for (int i = instart; i <= inend; i++)
    {
        if (rootVal == Inorder[i])
        {
            ind = i;
            break;
        }
    }
    root->right = solve(Inorder, postOrder, ind + 1, inend, postIndex);
    root->left = solve(Inorder, postOrder, instart, ind - 1, postIndex);

    return root;
}
Node *buildTree(int n, int in[], int post[])
{
    // Your code here
    vector<int> Inorder(in, in + n);
    vector<int> Postorder(post, post + n);
    int index = 0;
    int postIndex = n - 1;
    return solve(Inorder, Postorder, 0, n - 1, postIndex);
}