#include<bits/stdc++.h>
using namespace std;

void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node + 1 << " ";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[0] = 0;
    queue<int> pq;
    pq.push(0);

    while (!pq.empty()) {
        int u = pq.front();
        pq.pop();
        for (auto v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                pq.push(v);
            }
        }
    }

    if (dist[n - 1] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n - 1] + 1 << endl;
        printPath(n - 1, parent);
        cout << endl;
    }

    return 0;
}
