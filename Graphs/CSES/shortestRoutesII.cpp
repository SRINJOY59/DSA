#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>adj(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i = 1;i<=n;i++){
        adj[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    
    for(int k=1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    while(q--){
        ll a, b;
        cin>>a>>b;
        if(adj[a][b] != LLONG_MAX)
            cout<<adj[a][b]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}