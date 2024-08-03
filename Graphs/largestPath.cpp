#include <bits/stdc++.h> 
using namespace std;

void dfs(int start, vector<int>&vis, vector<vector<pair<int, int>>>&adj, stack<int>&st){
    vis[start] = 1;
    for(auto it:adj[start]){
        if(!vis[it.first]){
            dfs(it.first, vis, adj, st);
        }
    }
    st.push(start);
}
vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges) {

    vector<vector<pair<int, int>>>adj(n);
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        wt = (-1)*wt;
        adj[u].push_back({v, wt});
    }
    vector<int> vis(n, 0);
    int ans = 0;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    vector<int>dist(n, 1e9);
    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dist[node] != 1e9){
            for(auto it:adj[node]){
                dist[it.first] = min(dist[it.first], dist[node]+it.second);
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
        else
            dist[i] = (-1)*dist[i];
    }
    return dist;
}

