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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    map<string, int> mp;
    int n = accounts.size();
    DisjointSet dsu(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            if (mp.find(accounts[i][j]) != mp.end())
            {
                dsu.UnionBySize(mp[accounts[i][j]], i);
            }
            mp[accounts[i][j]] = i;
        }
    }

    vector<int> parents(n);
    for (int i = 0; i < n; i++)
    {
        parents[i] = dsu.findUPar(i);
    }

    map<int, set<string>> mergedAccounts;
    for (int i = 0; i < n; i++)
    {
        int parent = dsu.findUPar(i);
        for (int j = 1; j < accounts[i].size(); j++)
        {
            mergedAccounts[parent].insert(accounts[i][j]);
        }
    }

    vector<vector<string>> results;
    for (auto &entry : mergedAccounts)
    {
        vector<string> account(entry.second.begin(), entry.second.end());
        account.insert(account.begin(), accounts[entry.first][0]);
        results.push_back(account);
    }

    return results;
}