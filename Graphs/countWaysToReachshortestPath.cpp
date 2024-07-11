#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int wt = roads[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    int S = 0;
    vector<int> count(n, 0);
    dist[S] = 0;
    count[S] = 1;
    pq.push({0, S});
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (auto it : adj[node]) {
            int neigh = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[neigh]) {
                dist[neigh] = dist[node] + wt;
                count[neigh] = count[node];
                pq.push({dist[neigh], neigh});
            } else if (dist[node] + wt == dist[neigh]) {
                count[neigh] = (count[neigh] + count[node]) % 1000000007; // Modulo to avoid overflow
            }
        }
    }

    return count[n-1];
}