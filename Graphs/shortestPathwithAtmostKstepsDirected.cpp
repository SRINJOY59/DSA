#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        adj[u].push_back({v, wt});
    }

    // {steps, {node, cost}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front().second.first;
        int steps = q.front().first;
        int cost = q.front().second.second;
        q.pop();

        if (steps > K) {
            continue;
        }

        for (auto it : adj[node]) {
            int adjnode = it.first;
            int edgeW = it.second;
            if (cost + edgeW < dist[adjnode]) {
                dist[adjnode] = cost + edgeW;
                q.push({steps + 1, {adjnode, dist[adjnode]}});
            }
        }
    }

    int ans = dist[dst];
    return ans == INT_MAX ? -1 : ans;
}
