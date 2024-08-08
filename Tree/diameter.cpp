#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//O(N) approach
int height(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int diameter = 0;
    int ans = height(root, diameter);
    return diameter;
}