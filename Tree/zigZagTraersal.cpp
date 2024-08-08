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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return {};
    }
    q.push(root);
    int leftToRight = true;
    vector<vector<int>> answer;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++)
        {
            int index = 0;
            if (leftToRight)
            {
                index = i;
            }
            else
            {
                index = sz - i - 1;
            }
            TreeNode *node = q.front();
            level[index] = node->val;
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        leftToRight = 1 - leftToRight;
        answer.push_back(level);
    }
    return answer;
}
