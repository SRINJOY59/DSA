#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    // mark it visited
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    // push the node in queue
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    // until the queue becomes empty
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Only checking vertical movements
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            if (delrow == 0)
                continue;
            int nrow = row + delrow;
            int ncol = col;
            if (nrow >= 0 && nrow < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // create visited array and initialise to 0
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            // if not visited and is a land
            if (!vis[row][col] && grid[row][col] == '1')
            {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << numIslands(grid) << endl;
    }

    return 0;
}
