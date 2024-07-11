#include<bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> Indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for (auto& pre : prerequisites) {
        int v = pre[0]; 
        int u = pre[1];  // u is the prerequisite course of v
        adj[u].push_back(v);
        Indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (Indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int& neighbor : adj[node]) {
            Indegree[neighbor]--;
            if (Indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses;
}