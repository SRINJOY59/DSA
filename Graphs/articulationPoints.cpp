#include <bits/stdc++.h>
using namespace std;
int timer = 1;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<int> &mark)
{
    vis[node] = 1;
    low[node] = tin[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, adj, vis, tin, low, mark);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child += 1;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (child > 1 && parent == -1)
    {
        mark[node] = 1;
    }
}
vector<int> articulationPoints(int V, vector<int> adj[])
{
    // Code here
    int n = V;
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, vis, tin, low, mark);
        }
    }
    vector<int> points;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
        {
            points.push_back(i);
        }
    }
    if (points.size() > 0)
    {
        return points;
    }
    else
    {
        return {-1};
    }
}