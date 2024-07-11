#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int>adj[], vector<int>&color){
    color[node] = col;
    for(auto it : adj[node]){
        if(color[it] == -1){
            if(dfs(it, 1 - col, adj, color) == false){
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}
bool check(vector<int>adj[], vector<int>&color, int V){
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<int>color(n, -1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    if(check(adj, color, n)){
        for(int i = 0;i<n;i++){
            if(color[i] == 1){
                color[i] = 2;
            }
            else{
                color[i] = 1;
            }
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}