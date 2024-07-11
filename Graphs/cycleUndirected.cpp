#include<bits/stdc++.h>
using namespace std;
//bfs approach for cycle detection
bool solve(vector<int>adj[], int start, vector<bool>& vis) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = true;
    vector<int> answer;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int adjNode : adj[node]) {
            if (!vis[adjNode]) {
                q.push({adjNode, node});
                vis[adjNode] = true;
            } else if (adjNode != parent) {
                return true;
            }
        }
    }
    return false;
}
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V, false);
        for(int i= 0;i<V;i++){
            if(!vis[i]){
                if(solve(adj, i, vis)){
                    return true;
                }
            }
        }
        return false;
    }