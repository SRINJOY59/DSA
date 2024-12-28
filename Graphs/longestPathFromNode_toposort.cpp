//problem is to get the length of the longest path from each node

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int start, vector<vector<int>>&adj, vector<int>&vis, vector<int>&topo){
    vis[start] = 1;
    for(auto i: adj[start]){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    topo.push_back(start);
}   

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    vector<int>vis(n, 0);
    vector<int>topo;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    
    vector<int>dp(n, 0);
    int max_length = 0;

    for(auto node : topo){
        int ans = 1;
        for(auto it : adj[node]){
            ans = max(ans, 1 + dp[it]);
        }
        dp[node] = ans;
        max_length = max(max_length, ans);
    }

    cout<<max_length<<endl;
    return 0;
}