#include<bits/stdc++.h>
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


vector<vector<int>> levelOrder(TreeNode *root, vector<vector<int>>&edges)
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
                edges.push_back({topNode->val, topNode->left->val});
                q.push(topNode->left);
            }
            if (topNode->right != NULL){
                edges.push_back({topNode->val, topNode->right->val});
                q.push(topNode->right);
            }
            level.push_back(topNode->val);
        }
        answer.push_back(level);
    }
    return answer;
}


    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>>edges;
        vector<vector<int>>level = levelOrder(root, edges);
        if(level.size() == 1){
            return 0;
        }
        int n = 0;
        for(int i = 0;i<edges.size();i++){
            n = max(n, edges[i][0]);
            n = max(n, edges[i][1]);
        }
        n++;
        vector<vector<int>>adj(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        queue<pair<int, int>>q;
        q.push({start-1, 0});
        map<int, bool>mp;
        int maxi = 0;
        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            int node = p.first;
            int time = p.second;
            if(mp.find(node) == mp.end()){
                mp[node] = true;
            }
            maxi = max(maxi, time);
            for(auto it:adj[node]){
                if(mp.find(it) == mp.end()){
                    q.push({it, time+1});
                    mp[it] = true;
                }
            }
        }
        return maxi;
    }