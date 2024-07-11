#include <bits/stdc++.h>
using namespace std;
void topoSort(int start, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[start] = 1;
    for (auto it : adj[start])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(start);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(N, 0);
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, s);
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0; // source node

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (dist[node] != INT_MAX)
        { // Only process if node is reachable
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }

    return dist;
}