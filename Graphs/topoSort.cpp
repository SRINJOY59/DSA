// Topological Sorting using DFS
//
// This algorithm sorts vertices of a Directed Acyclic Graph (DAG)
// such that for every directed edge u -> v, vertex u comes before v in the ordering.
//
// Steps:
// 1. Initialize a visited array to track visited vertices.
// 2. Use DFS to visit each unvisited vertex.
// 3. Push vertices onto a stack once all their dependencies are visited.
// 4. Pop elements from the stack to get the topological sort order.
//
// Parameters:
// - V: Number of vertices in the graph.
// - adj: Adjacency list representation of the graph.
//
// Returns:
// - Vector containing vertices in topologically sorted order.
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (!vis[adjnode])
        {
            dfs(adjnode, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

vector<int>topoSortBFS(int V, vector<int>adj[]){
    vector<int>Indegree(V, 0);
    for(int i = 0;i<V;i++){
        for(auto it:adj[i]){
            Indegree[it]++;
        }
    }
    queue<int>q;
    for(int i = 0;i<Indegree.size();i++){
        if(Indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node =  q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            Indegree[it]--;
            if(Indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return topo;
}