#include <bits/stdc++.h>
using namespace std;

// You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

// Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    pq.push({0, {0, 0}});
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    while (!pq.empty())
    {
        int nodeX = pq.top().second.first;
        int nodeY = pq.top().second.second;
        int currentDist = pq.top().first;
        pq.pop();
        if (nodeX == n - 1 && nodeY == m - 1)
        {
            return currentDist;
        }
        for (int i = 0; i < 4; i++)
        {
            int newRow = nodeX + delRow[i];
            int newCol = nodeY + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                int neweffort = max(abs(heights[newRow][newCol] - heights[nodeX][nodeY]), currentDist);
                if (neweffort < dist[newRow][newCol])
                {
                    dist[newRow][newCol] = neweffort;
                    pq.push({neweffort, {newRow, newCol}});
                }
            }
        }
    }

    return 0;
}