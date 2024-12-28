#include <bits/stdc++.h>
using namespace std;

int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
    vector<vector<int>> adj(graph_nodes + 1);
    for (int i = 0; i < graph_from.size(); ++i) {
        adj[graph_from[i]].push_back(graph_to[i]);
        adj[graph_to[i]].push_back(graph_from[i]);
    }

    vector<bool> visited(graph_nodes + 1, false);

    function<int(int)> dfs = [&](int node) {
        visited[node] = true;
        int size = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                size += dfs(neighbor);
            }
        }
        return size;
    };

    int total_sum = 0;
    for (int i = 1; i <= graph_nodes; ++i) {
        if (!visited[i]) {
            int component_size = dfs(i);
            total_sum += ceil(sqrt(component_size));
        }
    }

    return total_sum;
}

int main() {
    int graph_nodes = 8;
    vector<int> graph_from = {8, 5, 7, 8};
    vector<int> graph_to = {1, 8, 3, 6};

    cout << connectedSum(graph_nodes, graph_from, graph_to) << endl;  
    return 0;
}
