#include<bits/stdc++.h>
using namespace std;

void subtreeSumDFS(vector<vector<int>>&adj, map<int, int>&mp, int node, int parent){
    mp[node] += node;

    for(auto it : adj[node]){
        if(it != parent){
            subtreeSumDFS(adj, mp, it, node);
            mp[node] += mp[it];
        }
    }
}

void subtreeEvencountDFS(vector<vector<int>>&adj, map<int, int>&mp, int node, int parent){
    if(node%2 == 0){
        mp[node]+=1;
    }

    for(auto it : adj[node]){
        if(it != parent){
            subtreeEvencountDFS(adj, mp, it, node);
            mp[node] += mp[it];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges(m);
    vector<vector<int>>adj(n);
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int, int>mp1;
    map<int, int>mp2;

    subtreeSumDFS(adj, mp1, 0, -1);
    subtreeEvencountDFS(adj, mp2, 0, -1);
    int q;
    cin>>q;
    while(q--){
        int v;
        cin >> v;
        cout << mp1[v] << " " << mp2[v] << "\n";
    }
    return 0;
}