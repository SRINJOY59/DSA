#include <bits/stdc++.h>
using namespace std;


//just we have to identify here nodes are  0 to 10^5 -1, and we have to find minimum steps to reach the node after multiplying with the elements of the array
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    vector<int> dist(100000, INT_MAX);
    queue<pair<int, int>> q;
    q.push({0, start});
    dist[start] = 0;
    while (!q.empty())
    {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();
        if (node == end)
        {
            return steps;
        }
        for (auto it : arr)
        {
            int val = (node * it) % 100000;
            if (dist[node] + 1 < dist[val])
            {
                dist[val] = dist[node] + 1;
                q.push({dist[val], val});
            }
        }
    }
    return -1;
}