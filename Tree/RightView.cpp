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

void f(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (level == res.size())
    {
        res.push_back(root->val);
    }
    f(root->right, level + 1, res);
    f(root->left, level + 1, res);
}
vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> res;
    f(root, 0, res);
    return res;
}


//iterative
vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    
    map<int, int> nodes; 
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int v = it.second;
        
        if(nodes.find(v) == nodes.end()){
            nodes[v] = node->val;
        }
        
        if (node->right != NULL)
            q.push({node->right, v + 1});
        if (node->left != NULL)
            q.push({node->left, v + 1});
    }
    
    for (auto p : nodes)
    {
        ans.push_back(p.second);
    }
    
    return ans;
}
