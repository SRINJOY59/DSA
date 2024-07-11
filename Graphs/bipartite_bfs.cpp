#include <bits/stdc++.h>
using namespace std;
// check using BFS if any two of the nodes have same color then it is not bipartite
bool bfs(int start, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = 1 - color[node];
            }
            if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
// DFS approach
bool dfs(int start, int col, vector<int> adj[], vector<int> &color)
{
    color[start] = col;
    for (auto node : adj[start])
    {
        if (color[node] == -1)
        {
            if (dfs(node, 1 - col, adj, color) == false)
            {
                return false;
            }
        }
        else if (color[node] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}