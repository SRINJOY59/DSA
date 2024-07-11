#include<bits/stdc++.h>
using namespace std;
void dfs(int n, int m, int row, int col, vector<vector<char>>& mat, vector<vector<bool>>& vis) {
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    vis[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + delrow[i];
        int newCol = col + delCol[i];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && mat[newRow][newCol] == 'O') {
            dfs(n, m, newRow, newCol, mat, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // Go for 1st row
    for (int i = 0; i < m; i++) {
        if (mat[0][i] == 'O' && !vis[0][i]) {
            dfs(n, m, 0, i, mat, vis);
        }
    }

    // Go for last row
    for (int i = 0; i < m; i++) {
        if (mat[n-1][i] == 'O' && !vis[n-1][i]) {
            dfs(n, m, n-1, i, mat, vis);
        }
    }

    // Go for 1st column
    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 'O' && !vis[i][0]) {
            dfs(n, m, i, 0, mat, vis);
        }
    }

    // Go for last column
    for (int i = 0; i < n; i++) {
        if (mat[i][m-1] == 'O' && !vis[i][m-1]) {
            dfs(n, m, i, m-1, mat, vis);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'O' && !vis[i][j]) {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}