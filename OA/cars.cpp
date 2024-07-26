#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&A, vector<int>&B, int index, int prev, int n, int cost, vector<vector<int>>&dp){
    if(index >= n){
        return 0;
    }
    int Apath = INT_MAX;
    int Bpath = INT_MAX;
    if(dp[index][prev] != -1){
        return dp[index][prev];
    }
    if(prev == 0){
        Apath = A[index] + solve(A, B, index+1, 1, n, cost, dp);
        Bpath = cost + B[index] + solve(A, B, index+1, 2, n, cost, dp);
    }
    else if(prev == 1){
        Apath = A[index] + solve(A, B, index+1, 1, n, cost, dp);
        Bpath = cost + B[index] + solve(A, B, index+1, 2, n, cost, dp);
    }
    else{
        Apath = A[index] + solve(A, B, index+1, 1, n, cost, dp);
        Bpath = B[index] + solve(A, B, index+1, 2, n, cost, dp);
    }
    return dp[index][prev] = min(Apath, Bpath);
}

int main(){
    int n;
    cin>>n;
    vector<int>A(n), B(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    for(int i = 0; i < n; i++){
        cin>>B[i];
    }
    int cost = 0;
    cin>>cost;
    vector<vector<int>>dp(n, vector<int>(3, -1));
    int val = solve(A, B, 0, 0, n, cost, dp);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int>final(n+1);
    for(int i = 0; i < n; i++){
        dp = vector<vector<int>>(n, vector<int>(3, -1));
        final[i] = solve(A, B, 0, 0, i,cost, dp);
    }
    final[n] = val;
    cout<<endl;
    for(int i = 0; i < n+1; i++){
        cout<<final[i]<<" ";
    }
    cout<<endl;
    return 0;
}