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

string serialize(TreeNode *root)
{
    if (!root)
        return "";

    string ans = "";
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr)
        {
            ans += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            ans += "#,";
        }
    }

    if (!ans.empty())
    {
        ans.pop_back();
    }

    return ans;
}

TreeNode *deserialize(string data)
{
    if (data.empty())
        return NULL;

    stringstream ss(data);
    string item;
    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (getline(ss, item, ','))
        {
            if (item != "#")
            {
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }
        }

        if (getline(ss, item, ','))
        {
            if (item != "#")
            {
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
    }

    return root;
}