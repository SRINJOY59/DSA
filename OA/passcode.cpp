#include<bits/stdc++.h>
using namespace std;

int solve(string password, string code, int n, int m, int index, int indC, vector<vector<int>>&dp){

    if(indC >= m){
        return 0;
    }
    if(index >= n){
        index = 0;
    }
    if(index < 0){
        index = n-1;
    }
    if(dp[index][indC] != - 1){
        return dp[index][indC];
    }
    if(password[index] == code[indC]){
        dp[index][indC] =  1 + solve(password, code, n, m, index, indC+1, dp);
    }
    else{
        int val1 = 1 + solve(password, code, n, m, (index + 1), indC, dp);
        int val2 = 1 + solve(password, code, n, m, (index-1), indC, dp);
        dp[index][indC] = min(val1, val2);
    }
    return dp[index][indC];
}

int main(){

    string password, code;
    cin>>password>>code;
    int n = password.length();
    int m = code.length();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    cout<<solve(password, code, n, m, 0, 0, dp);
    return 0;
}