#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int , pair<int, int>>>> pq;
    vector<bool> vis(V, false);
    vector<pair<int, pair<int, int>>> mst;
    //wt, node, parent
    pq.push({0, {0, -1}});
    int sum = 0;
    
    while (!pq.empty()) {
        int node = pq.top().second.first;
        int wt = pq.top().first;
        int parent = pq.top().second.second;
        pq.pop();
        
        if (vis[node]) {
            continue;
        }
        
        vis[node] = true;
        sum += wt;
        mst.push_back({wt, {node, parent}});
        for (auto it : adj[node]) {
            int adjnode = it[0];
            int edgeW = it[1];
            
            if (!vis[adjnode]) {
                pq.push({edgeW, {adjnode, node}});
            }
        }
    }
    
    cout << "Edges in the MST:" << endl;
    for (auto edge : mst) {
        if (edge.first != 0) {
            cout << edge.second.first << " - " << edge.second.second << " with weight " << edge.first << endl;
        }
    }
    
    return sum;
}

int main() {
    int V = 5;
    vector<vector<int>> adj[5];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    
    int totalWeight = spanningTree(V, adj);
    cout << "Total weight of the MST: " << totalWeight << endl;
    
    return 0;
}
