// dfs approach using visited and pathvisited array
//  if both of them is true and cycle present, we have to actually get a node which has to be visited again in the same path
#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int start, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis)
{
    vis[start] = 1;
    pathvis[start] = 1;
    for (auto node : adj[start])
    {
        if (!vis[node])
        {
            if (dfsCheck(node, adj, vis, pathvis))
            {
                return true;
            }
        }
        else if (pathvis[node])
        {
            return true;
        }
    }
    pathvis[start] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> vis(V, false);
    vector<bool> pathvis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathvis))
            {
                return true;
            }
        }
    }
    return false;
}