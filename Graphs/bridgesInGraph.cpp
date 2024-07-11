/*
Tarjan's Algorithm to Find Bridges in a Graph:

1. Initialize discovery time and low value arrays (tin and low) and a visited array.
2. Perform a DFS traversal of the graph.
3. For each node, record its discovery time and low value.
4. For each adjacent node:
   a. If it is not visited, perform DFS on it.
   b. After returning from DFS, update the current node's low value based on the adjacent node's low value.
   c. If the adjacent node's low value is greater than the current node's discovery time, the edge between the two is a bridge.
   d. If it is visited but not the parent, update the current node's low value based on the adjacent node's discovery time.
5. Return the list of bridges.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int timer;

public:
    Solution() : timer(1) {}

    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        fill(tin, tin + n, -1);
        fill(low, low + n, -1);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, tin, low, bridges);
            }
        }
        return bridges;
    }
};

int main()
{
    int n = 5; // Number of nodes
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    Solution solution;
    vector<vector<int>> bridges = solution.criticalConnections(n, connections);

    cout << "Bridges in the graph:\n";
    for (const auto &bridge : bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
