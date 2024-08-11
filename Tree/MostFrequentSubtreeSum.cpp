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

int dfs(TreeNode *root, map<int, int> &mp, int &sum)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = dfs(root->left, mp, sum);
    int right = dfs(root->right, mp, sum);
    sum = root->val + left + right;
    mp[sum] += 1;
    return sum;
}
vector<int> findFrequentTreeSum(TreeNode *root)
{
    map<int, int> mp;
    int sum = 0;
    dfs(root, mp, sum);
    vector<pair<int, int>> p;
    for (auto it : mp)
    {
        p.push_back({it.second, it.first});
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    vector<int> ans;
    int maxi = p[0].first;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].first == maxi)
        {
            ans.push_back(p[i].second);
        }
    }
    return ans;
}