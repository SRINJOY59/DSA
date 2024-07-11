#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        matrix[u][v] = wt;
        matrix[v][u] = wt;
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                {
                    continue;
                }
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            }
        }
    }
    int cityCnt = n;
    int city = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] <= distanceThreshold)
            {
                count += 1;
            }
        }
        if (count <= cityCnt)
        {
            cityCnt = count;
            city = i;
        }
    }

    return city;
}