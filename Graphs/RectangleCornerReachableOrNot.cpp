#include<bits/stdc++.h>
using namespace std;

long double distanceFromPointToLine(long double A, long double B, long double C, long double x, long double y) {
    return abs(A * x + B * y + C) / sqrt(A * A + B * B);
}

bool isTangent(long double h, long double k, long double r, long double A, long double B, long double C) {
    long double distance = distanceFromPointToLine(A, B, C, h, k);
    return distance <= r;
}

void bfs(const vector<vector<long long>>& circles, map<long long, vector<long long>>& adj, vector<bool>& visited, long long start) {
    queue<long long> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        long long node = q.front();
        q.pop();
        for (auto& it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

bool canReachCorner(long long X, long long Y, const vector<vector<long long>>& circles) {
    long long n = circles.size();
    map<long long, vector<long long>> adj;
    vector<bool> visited(n, false);

    for (long long i = 0; i < n; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            long double dist = sqrt((circles[i][0] - circles[j][0]) * (circles[i][0] - circles[j][0]) + 
                                    (circles[i][1] - circles[j][1]) * (circles[i][1] - circles[j][1]));
            if (dist <= (circles[i][2] + circles[j][2])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    set<long long> bottomEdge, leftEdge, topEdge, rightEdge;
    for (long long i = 0; i < n; ++i) {
        if (circles[i][1] - circles[i][2] <= 0) bottomEdge.insert(i);
        if (circles[i][0] - circles[i][2] <= 0) leftEdge.insert(i);
        if (circles[i][1] + circles[i][2] >= Y) topEdge.insert(i);
        if (circles[i][0] + circles[i][2] >= X) rightEdge.insert(i);
    }

    auto isConnected = [&](const set<long long>& startSet, const set<long long>& endSet) {
        for (long long start : startSet) {
            fill(visited.begin(), visited.end(), false);
            bfs(circles, adj, visited, start);
            for (long long end : endSet) {
                if (visited[end]) return true;
            }
        }
        return false;
    };

    if (isConnected(bottomEdge, leftEdge) || isConnected(bottomEdge, topEdge) ||
        isConnected(rightEdge, leftEdge) || isConnected(rightEdge, topEdge)) {
        return false;
    }

    return true;
}