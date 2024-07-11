#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;

int N, M, start, finish;
vector<int> G[maxN];
vector<int> parent(maxN, -1);
vector<int> path;
vector<bool> visited(maxN, false);
bool cycle_found = false;

void dfs(int u) {
    visited[u] = true;
    for (int v : G[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            if (cycle_found) return; 
        } else if (v != parent[u]) {
            start = v;
            finish = u;
            cycle_found = true;
            return;
        }
    }
}

void findCycle() {
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            if (cycle_found) return; 
        }
    }
}

void printCyclePath() {
    if (!cycle_found) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int current = finish;
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    path.push_back(finish); 
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a); 
    }

    findCycle();
    printCyclePath();

    return 0;
}
