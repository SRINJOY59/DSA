#include<bits/stdc++.h>
using namespace std;

// There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// A node is good if all the 
// subtrees
//  rooted at its children have the same size.

// Return the number of good nodes in the given tree.

// A subtree of treeName is a tree consisting of a node in treeName and all of its descendants.

int dfs(vector<vector<int>>&adj, int node, int parent, map<int, int>TreeSize, int &countGoodNodes){
    int size = 1;
    int expected_size = -1;
    bool check = true;
    for(auto neigh : adj[node]){
        if(neigh != parent){
            int subtree = dfs(adj, neigh, node, TreeSize, countGoodNodes);
            if(expected_size == -1){
                expected_size = subtree;
            }
            else if(expected_size != subtree){
                check = false;
            }
            size += subtree;
        }
    }
    TreeSize[node] = size;
    if(check){
        countGoodNodes += 1;
    }
    return size;
}

int countGoodNodes(vector<vector<int>>&edges){
    int n = edges.size()+1;
    vector<vector<int>>adj(n);
    map<int, int>TreeSize;
    int countGoodNodes = 0;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, 0, -1, TreeSize, countGoodNodes);
    return countGoodNodes;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges(m, vector<int>(2));
    for(int i = 0;i<m;i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << countGoodNodes(edges) << endl;
    return 0;
}