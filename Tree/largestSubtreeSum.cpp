#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int dfs(Node *root, unordered_map<int, int> &mp)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = dfs(root->left, mp);
    int right = dfs(root->right, mp);
    int sum = root->data + left + right;
    mp[sum] += 1;
    return sum;
}
int findLargestSubtreeSum(Node *root)
{
    unordered_map<int, int> mp;
    int val = dfs(root, mp);
    int maxi = INT_MIN;
    for (auto it : mp)
    {
        maxi = max(maxi, it.first);
    }
    return maxi;
}