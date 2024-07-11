#include<bits/stdc++.h>
using namespace std;

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    
    vector<vector<vector<pair<int, int>>>> adj(N, vector<vector<pair<int, int>>>(M));
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if (A[i][j] == 1) {
                for(int k = 0; k < 4; ++k) {
                    int newRow = i + delRow[k];
                    int newCol = j + delCol[k];
                    if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && A[newRow][newCol] == 1) {
                        adj[i][j].push_back({newRow, newCol});
                        adj[newRow][newCol].push_back({i, j});
                    }
                }
            }
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    

    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    dist[0][0] = 0;
    
    pq.push({0, {0, 0}});
    
    while (!pq.empty()) {
        int nodeX = pq.top().second.first;
        int nodeY = pq.top().second.second;
        int currentDist = pq.top().first;
        pq.pop();
        
        for (const auto& neighbor : adj[nodeX][nodeY]) {
            int neighX = neighbor.first;
            int neighY = neighbor.second;
            if (currentDist + 1 < dist[neighX][neighY]) {
                dist[neighX][neighY] = currentDist + 1;
                pq.push({dist[neighX][neighY], {neighX, neighY}});
            }
        }
    }
    
    if (dist[X][Y] == INT_MAX) {
        return -1;
    }
    
    return dist[X][Y];
}