#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool getPath(TreeNode *A, vector<int> &arr, int x)
{
    if (A == NULL)
        return false;

    arr.push_back(A->val);
    if (A->val == x)
        return true;
    if (getPath(A->left, arr, x) || getPath(A->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> arr;
    if (A == NULL)
        return arr;
    bool f = getPath(A, arr, B);
    return arr;
}
