#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

bool func(BinaryTreeNode<int> *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= maxi || root->data <= mini)
    {
        return false;
    }

    return func(root->left, mini, root->data) & func(root->right, root->data, maxi);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return func(root, mini, maxi);
}