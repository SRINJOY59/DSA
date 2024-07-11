/*
Algorithm to find eventual safe nodes in a directed graph:

1. Define a helper function `dfsCheck` to perform depth-first search (DFS) on the graph:
   - If the current node is already visited:
     - Return true if it is marked as visiting (indicating a cycle).
     - Return false if it is marked as safe.
   - Mark the current node as visiting.
   - Recursively check all neighbors of the current node:
     - If any neighbor leads to a cycle, return true.
   - Mark the current node as safe and return false.

2. In the main function `eventualSafeNodes`:
   - Initialize a vector `vis` to keep track of the state of each node (0: unvisited, 1: visiting, 2: safe).
   - Initialize a vector `ans` to store the eventual safe nodes.
   - For each node in the graph:
     - If the node does not lead to a cycle (using `dfsCheck`), add it to the `ans` vector.
   - Return the `ans` vector containing all the eventual safe nodes.
*/

#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int start, vector<int> adj[], vector<int> &vis) {
    if (vis[start] != 0) {
        return vis[start] == 1;
    }

    vis[start] = 1;  

    for (auto node : adj[start]) {
        if (dfsCheck(node, adj, vis)) {
            return true;
        }
    }

    vis[start] = 2;  
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++) {
        if (!dfsCheck(i, adj, vis)) {
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    //bfs - Kahn's algorithm approach
    vector<int> Indegree(V, 0);  
    vector<vector<int>> adjRev(V);  
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            adjRev[neighbor].push_back(i); 
            Indegree[i]++;  
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (Indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> eventuallySafe;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        eventuallySafe.push_back(node);

        for (int neighbor : adjRev[node]) {
            Indegree[neighbor]--;

            if (Indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }


    sort(eventuallySafe.begin(), eventuallySafe.end());
    
    return eventuallySafe;
}