#include <bits/stdc++.h>
using namespace std;

void printPath(int node, const vector<int> &parent, vector<int> &answer)
{
    if (node == -1)
    {
        return;
    }
    printPath(parent[node], parent, answer);
    answer.push_back(node);
}

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto &edge : edges)
    {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
        adj[edge[1]].emplace_back(edge[0], edge[2]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    vector<int> parent(n + 1, -1);

    pq.push({0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dst = pq.top().first;
        pq.pop();

        for (const auto &it : adj[node])
        {
            int neigh = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[neigh])
            {
                dist[neigh] = dist[node] + wt;
                parent[neigh] = node;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    vector<int> path;
    printPath(n, parent, path);

    if (path.empty() || path[0] != 1)
    {
        return {-1};
    }

    path.insert(path.begin(), dist[n]);

    return path;
}