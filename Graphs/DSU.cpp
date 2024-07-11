#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank,size ,parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v)
            return;
        
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;  
            rank[ulp_u]++;          
        }
    }
    void UnionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return ;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet DSU(7);
    // DSU.unionByRank(1, 2);
    // DSU.unionByRank(2, 3);
    // DSU.unionByRank(4, 5);
    // DSU.unionByRank(6, 7);
    // DSU.unionByRank(5, 6);
    
    // if (DSU.findUPar(3) == DSU.findUPar(7)) {
    //     cout << "Belongs to same component" << endl;
    // } else {
    //     cout << "Does not belong to same component" << endl;
    // }
    
    // DSU.unionByRank(3, 7);
    
    // if (DSU.findUPar(3) == DSU.findUPar(7)) {
    //     cout << "3 and 7 belong to same graph" << endl;
    // } else {
    //     cout << "They don't belong to same graph!!" << endl;
    // }
    DSU.UnionBySize(1, 2);
    DSU.UnionBySize(2, 3);
    DSU.UnionBySize(4, 5);
    DSU.UnionBySize(6, 7);
    DSU.UnionBySize(5, 6);
    
    if (DSU.findUPar(3) == DSU.findUPar(7)) {
        cout << "Belongs to same component" << endl;
    } else {
        cout << "Does not belong to same component" << endl;
    }
    
    DSU.UnionBySize(3, 7);
    
    if (DSU.findUPar(3) == DSU.findUPar(7)) {
        cout << "3 and 7 belong to same graph" << endl;
    } else {
        cout << "They don't belong to same graph!!" << endl;
    }
    return 0;
}
