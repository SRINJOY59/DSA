#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            }
        }
    }

    //detect negative cycles
    for(int i = 0;i<n;i++){
        if(matrix[i][i] < 0){
            cout<<"Negative Cycle is present in the graph!!!"<<endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}