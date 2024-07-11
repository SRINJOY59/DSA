#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, adj);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int count = 0;
    vector<pair<int, int>> ans;
    int lastNode = -1;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (lastNode != -1) {
                ans.push_back({lastNode + 1, i + 1});
                count++;
            }
            dfs(i, vis, adj);
            lastNode = i; 
        }
    }
    cout << count << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}
