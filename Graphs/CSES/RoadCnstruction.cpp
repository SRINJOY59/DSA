#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> size, parent;
    multiset<int> unique_parents;
    int maxSize = 0;
    int prev = -1;
    int uniqueCnt = 0;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; 
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]); 
    }

    void unionBySize(int u, int v, int n) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if (ulp_u == ulp_v) {
            int sz = unique_parents.size();
            cout << max(0, n - sz) << " " << maxSize << endl;
        }
        
        else if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            unique_parents.insert(ulp_u);
            size[ulp_u] += size[ulp_v];
            maxSize = max(maxSize, size[ulp_u]);
            int sz = unique_parents.size();
            cout << max(0, n - sz) << " " << maxSize << endl;
        } else {
            parent[ulp_u] = ulp_v;
            unique_parents.insert(ulp_v);
            size[ulp_v] += size[ulp_u];
            maxSize = max(maxSize, size[ulp_v]);
            int sz = unique_parents.size();
            cout << max(0, n - sz) << " " << maxSize << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n);
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        ds.unionBySize(u, v, n);
    }
    
    return 0;
}
