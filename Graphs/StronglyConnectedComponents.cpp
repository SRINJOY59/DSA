#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}
void dfs1(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, adj, vis);
        }
    }
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    vector<int> vis1(V, 0);
    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis1[node])
        {
            cnt += 1;
            dfs1(node, adjT, vis1);
        }
    }
    return cnt;
}

//overall complexity O(V+E)
//space complexity 0(2*V)

