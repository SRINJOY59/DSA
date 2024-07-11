//very similar to replae Os with Xs

#include<bits/stdc++.h>
using namespace std;

  void dfs(int n, int m, int row, int col, vector<vector<int>>& mat, vector<vector<bool>>& vis) {
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    vis[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + delrow[i];
        int newCol = col + delCol[i];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && mat[newRow][newCol] == 1) {
            dfs(n, m, newRow, newCol, mat, vis);
        }
    }
}
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<bool>> vis(n, vector<bool>(m, false));

    // Go for 1st row
    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1 && !vis[0][i]) {
            dfs(n, m, 0, i, grid, vis);
        }
    }

    // Go for last row
    for (int i = 0; i < m; i++) {
        if (grid[n-1][i] == 1 && !vis[n-1][i]) {
            dfs(n, m, n-1, i, grid, vis);
        }
    }

    // Go for 1st column
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1 && !vis[i][0]) {
            dfs(n, m, i, 0, grid, vis);
        }
    }

    // Go for last column
    for (int i = 0; i < n; i++) {
        if (grid[i][m-1] == 1 && !vis[i][m-1]) {
            dfs(n, m, i, m-1, grid, vis);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                count++;
            }
        }
    }
    return count;
    }