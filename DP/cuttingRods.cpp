#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, vector<int>&price, vector<vector<int>>&dp){
	if(n == 0){
		return 0;
	}
	if(index == 0){
		return n*price[0];
	}
	if(dp[index][n] != -1){
		return dp[index][n];
	}
	int take = INT_MIN;
	if(n >= index+1)
		take = price[index] + solve(index, n - index - 1, price, dp);
	int notTake = solve(index - 1, n, price, dp);
	int ans = max(take, notTake);
	dp[index][n] = ans;
	return ans;
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n, vector<int>(n+1, 0));
	// return solve(n-1, n, price, dp);
	
	for(int i = 0;i<=n;i++){
		dp[0][i] = i*price[0];
	}
	for(int i = 1;i<n;i++){
		for(int sz = 0;sz<=n;sz++){
			int take = INT_MIN;
			if(sz >= i+1)
				take = price[i] + dp[i][sz - i - 1];
			int notTake = dp[i - 1][sz];
			int ans = max(take, notTake);
			dp[i][sz] = ans;
		}
	}
	return dp[n-1][n];
}