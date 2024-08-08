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

vector<vector<int>> levelOrder(TreeNode *root)
{
    TreeNode *node = root;
    if (node == NULL)
    {
        return {};
    }
    queue<TreeNode *> q;
    q.push(node);
    vector<vector<int>> answer;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *topNode = q.front();
            q.pop();
            if (topNode->left != NULL)
            {
                q.push(topNode->left);
            }
            if (topNode->right != NULL)
                q.push(topNode->right);
            level.push_back(topNode->val);
        }
        answer.push_back(level);
    }
    return answer;
}
