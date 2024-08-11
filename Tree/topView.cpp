#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{
    // Your code here
    map<int, int> nodes;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int v = it.second;
        if (nodes.find(v) == nodes.end())
        {
            nodes[v] = node->data;
        }
        if (node->left)
            q.push({node->left, v - 1});
        if (node->right)
            q.push({node->right, v + 1});
    }
    for (auto p : nodes)
    {
        ans.push_back(p.second);
    }
    return ans;
}