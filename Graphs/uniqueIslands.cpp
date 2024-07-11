#include<bits/stdc++.h>
using namespace std;

    vector<pair<int , int>>bfs(int row, int col,int n, int m, vector<vector<int>>& grid, vector<vector<bool>>&vis){
        vis[row][col] = true;
        queue<pair<int, int>>q;
        q.push({row, col});
        vector<pair<int, int>>answer;
        while(!q.empty()){
            vector<int>delRow = {-1, 0, 1, 0};
            vector<int>delCol = {0, -1, 0, 1};
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            answer.push_back({row, col});
            for(int i = 0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                    vis[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return answer;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        set<vector<pair<int, int>>>s;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>>ans = bfs(i, j,n, m, grid, vis);
                    pair<int, int>base = ans[0];
                    for(int i = 0;i<ans.size();i++){
                        ans[i].first = ans[i].first - base.first;
                        ans[i].second = ans[i].second - base.second;
                    }
                    s.insert(ans);
                }
            }
        }
        int ans = s.size();
        return ans;
    }

//basically for each bfs we are getting unqiue patterns
//target is to get those unqiue patterns
//that is why the bfs pair array is substracted from the base pair