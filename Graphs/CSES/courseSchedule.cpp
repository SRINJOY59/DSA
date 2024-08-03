#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int start, stack<int>& st, vector<int>& vis) {
    vis[start] = 1;
    for (auto it : adj[start]) {
        if (!vis[it]) {
            dfs(adj, it, st, vis);
        }
    }
    st.push(start);
}

bool dfsCheck(int start, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathvis) {
    vis[start] = 1;
    pathvis[start] = 1;
    for (auto node : adj[start]) {
        if (!vis[node]) {
            if (dfsCheck(node, adj, vis, pathvis)) {
                return true;
            }
        } else if (pathvis[node]) {
            return true;
        }
    }
    pathvis[start] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    vector<bool> pathvis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathvis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    stack<int> st;
    if (isCyclic(n, adj)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(adj, i, st, vis);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        ans.push_back(top);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
