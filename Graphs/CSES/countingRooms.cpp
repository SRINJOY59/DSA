#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<int, int>> bfs(int row, int col, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
    vis[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});
    vector<pair<int, int>> answer;
    while (!q.empty())
    {
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        answer.push_back({row, col});
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '.')
            {
                vis[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
    return answer;
}
int countDistinctIslands(vector<vector<char>> &grid)
{
    // code here
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> s;
    vector<vector<pair<int, int>>>val;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                vector<pair<int, int>> ans = bfs(i, j, n, m, grid, vis);
                val.push_back(ans);
            }
        }
    }
    int ans = val.size();
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans = countDistinctIslands(grid);
    cout<<ans<<endl;
    return 0;
}