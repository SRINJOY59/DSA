#include<bits/stdc++.h>
using namespace std;

// n <= 500

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int node = pq.top().second;
        int dst = pq.top().first;
        pq.pop();

        if (dst > dist[node]) continue;

        for (auto it : adj[node]) {
            int neigh = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[neigh]) {
                dist[neigh] = dist[node] + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    return dist;
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        adj[i].push_back({i + 1, 1});
    }
    vector<int> ans;
    vector<int> dist = dijkstra(n, adj, 0); 

    for (int i = 0; i < queries.size(); i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        adj[u].push_back({v, 1});

        if (dist[u] + 1 < dist[v]) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[v] = dist[u] + 1;
            pq.push({dist[v], v});

            while (!pq.empty()) {
                int node = pq.top().second;
                int dst = pq.top().first;
                pq.pop();

                if (dst > dist[node]) continue;

                for (auto it : adj[node]) {
                    int neigh = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[neigh]) {
                        dist[neigh] = dist[node] + wt;
                        pq.push({dist[neigh], neigh});
                    }
                }
            }
        }
        
        ans.push_back(dist[n-1]);
    }
    return ans;
}