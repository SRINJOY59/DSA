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

void Inorder(Node *root, int k, int &count, int &ans)
{

    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, k, count, ans);
    count += 1;
    if (count == k)
    {
        ans = root->data;
        return;
    }
    Inorder(root->right, k, count, ans);
}
int KthSmallestElement(Node *root, int K)
{
    // add code here.
    int cnt = 0;
    int ans = -1;
    Inorder(root, K, cnt, ans);
    return ans;
}