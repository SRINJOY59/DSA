#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    return (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] != '#' && !visited[row][col]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
    int startRow, startCol, endRow, endCol;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startRow = i;
                startCol = j;
            }
            if (grid[i][j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    vector<int> delRow = {-1, 1, 0, 0};
    vector<int> delCol = {0, 0, -1, 1};
    vector<char> directions = {'U', 'D', 'L', 'R'};

    bool found = false;

    while (!q.empty() && !found) {
        pair<int, int>p = q.front();
        int currentRow = p.first;
        int currentCol = p.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + delRow[i];
            int newCol = currentCol + delCol[i];

            if (isValid(newRow, newCol, n, m, visited, grid)) {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = {currentRow, currentCol};
                q.push({newRow, newCol});

                if (grid[newRow][newCol] == 'B') {
                    found = true;
                    endRow = newRow;
                    endCol = newCol;
                    break;
                }
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        string path;
        int pathLength = 0;

        pair<int, int> current = {endRow, endCol};

        while (current != make_pair(startRow, startCol)) {
            pair<int, int> prev = parent[current.first][current.second];
            if (prev.first == current.first - 1) {
                path += 'D';
            } else if (prev.first == current.first + 1) {
                path += 'U';
            } else if (prev.second == current.second - 1) {
                path += 'R';
            } else if (prev.second == current.second + 1) {
                path += 'L';
            }
            current = prev;
            pathLength++;
        }

        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << pathLength << endl;
        cout << path << endl;
    }

    return 0;
}
