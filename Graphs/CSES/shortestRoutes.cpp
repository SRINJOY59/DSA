#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll INF = LLONG_MAX;
 
int main() {
    ll n, m;
    cin >> n >> m;
 
    vector<vector<pair<ll, ll>>> adj(n + 1); 
 
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    vector<ll> dist(n + 1, INF);
    dist[1] = 0; 
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1}); 
 
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
 
        if (d > dist[u]) continue; 
 
        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll len = edge.second;
 
            if (dist[u] + len < dist[v]) {
                dist[v] = dist[u] + len;
                pq.push({dist[v], v});
            }
        }
    }
 
    for (ll i = 1; i <= n; ++i) {
        if(dist[i] != INF)
            cout << dist[i] << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
 
    return 0;
}
