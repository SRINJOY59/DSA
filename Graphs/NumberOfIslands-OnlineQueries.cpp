#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    // code here
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    DisjointSet dsu(n * m);
    vector<int> ans;
    int cnt = 0;
    for (auto it : operators)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col])
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delrow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                if (vis[newRow][newCol])
                {
                    int nodeNo = row * m + col;
                    int adjnodeNo = newRow * m + newCol;
                    if (dsu.findUPar(nodeNo) != dsu.findUPar(adjnodeNo))
                    {
                        cnt--;
                        dsu.UnionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}