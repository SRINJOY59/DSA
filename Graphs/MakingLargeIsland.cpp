#include <bits/stdc++.h>
using namespace std;

// we are allowed to only change one 0 to 1 to make a larger island

class DisjointSet
{

public:
    vector<int> rank, size, parent;
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

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> operators;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                operators.push_back({i, j});
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    DisjointSet dsu(n * m);
    for (auto it : operators)
    {
        int row = it.first;
        int col = it.second;
        if (vis[row][col])
        {
            continue;
        }
        vis[row][col] = 1;
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
                        dsu.UnionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
    }
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                vector<int> delrow = {-1, 0, 1, 0};
                vector<int> delCol = {0, -1, 0, 1};

                int sz = 0;
                set<int> comp;
                for (int k = 0; k < 4; k++)
                {
                    int newRow = i + delrow[k];
                    int newCol = j + delCol[k];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                    {
                        if (grid[newRow][newCol] == 1)
                        {
                            int adjnode = newRow * m + newCol;
                            comp.insert(dsu.findUPar(adjnode));
                        }
                    }
                }

                for (auto it : comp)
                {
                    sz += dsu.size[it];
                }
                maxSize = max(maxSize, sz + 1);
            }
        }
    }
    //if all elements are already 1
    for (int i = 0; i < n * n; i++)
    {
        maxSize = max(maxSize, dsu.size[dsu.findUPar(i)]);
    }
    return maxSize;
}