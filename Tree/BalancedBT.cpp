#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalancedBT(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
    {
        return true;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) <= 1 && isBalancedBT(root->left) && isBalancedBT(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}