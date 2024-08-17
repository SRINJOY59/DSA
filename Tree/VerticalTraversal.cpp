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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    vector<vector<int>> ans;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int v = it.second.first;
        int l = it.second.second;
        nodes[v][l].insert(node->val);
        if (node->left)
            q.push({node->left, {v - 1, l + 1}});
        if (node->right)
            q.push({node->right, {v + 1, l + 1}});
    }
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}