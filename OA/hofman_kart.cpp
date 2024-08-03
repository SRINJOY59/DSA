#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int v, vector<int>& color) {
    queue<int> q;
    q.push(v);
    color[v] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];

            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int findMaxEdgesToCut(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!isBipartite(graph, i, color)) {
                int cutEdges = 0;
                vector<int> count(2, 0);

                for (int j = 0; j < n; ++j) {
                    if (color[j] != -1) {
                        count[color[j]]++;
                    }
                }

                for (int u = 0; u < n; ++u) {
                    for (int v : graph[u]) {
                        if (color[u] == color[v]) {
                            cutEdges++;
                        }
                    }
                }
                return cutEdges / 2;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int result = findMaxEdgesToCut(graph, n);
    cout << result << endl;

    return 0;
}
