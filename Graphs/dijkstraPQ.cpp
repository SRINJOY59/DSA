#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dst = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int neigh = it[0];
            int wt = it[1];
            if (dist[node] + wt < dist[neigh])
            {
                dist[neigh] = dist[node] + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    return dist;
}

//using set
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    set<pair<int, int>> setds;  // Create a set to store vertices that are being preprocessed
    vector<int> dist(V, INT_MAX);  // Initialize distances to all vertices as infinite
    dist[S] = 0;  // Distance to the source is 0
    setds.insert({0, S});  // Insert source vertex with distance 0

    while (!setds.empty()) {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int node = tmp.second;  // Extract the vertex with the minimum distance value
        int dst = tmp.first;

        // Iterate through all adjacent vertices of the extracted vertex
        for (auto it : adj[node]) {
            int neigh = it[0];
            int wt = it[1];

            // If there is a shorter path to the neighbor through this vertex
            if (dist[node] + wt < dist[neigh]) {
                // If the neighbor is in the set, remove it (as the distance is updated)
                if (dist[neigh] != INT_MAX) {
                    setds.erase(setds.find({dist[neigh], neigh}));
                }

                // Update the distance to the neighbor
                dist[neigh] = dist[node] + wt;
                setds.insert({dist[neigh], neigh});  // Insert the neighbor with the updated distance
            }
        }
    }

    return dist;
}