#include<bits/stdc++.h>
using namespace std;

int solve(int index1, int index2, vector<vector<int>>&triangle, int n, vector<vector<int>>&dp){
	if(index1 == n - 1){
		return triangle[index1][index2];
	}
	if(index1 >= n || index2 >= triangle[index1].size()){
		return 0;
	}
	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}
	int start1 = triangle[index1][index2] + solve(index1+1, index2, triangle, n,dp);
	int start2 = triangle[index1][index2] + solve(index1 + 1, index2 + 1, triangle, n, dp);
	int ans = min(start1, start2);
	dp[index1][index2] = ans;
	return dp[index1][index2];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>>dp(n, vector<int>(n, 0));
	// int ans = solve(0, 0, triangle, n, dp);

	// return ans;

    //tabulation
    for(int i = 0;i<n;i++){
		dp[n-1][i] = triangle[n-1][i];
	}
	for(int i = n-2;i>=0;i--){
		for(int j = 0;j<=i;j++){
			if(i == n - 1){
				dp[i][j] = triangle[i][j];
			}
			else{
				int start1 = 1e9;
				int start2 = 1e9;
				if(i < n-1){
					start1 = dp[i+1][j] + triangle[i][j];
				}
				if(i < n-1 && j < n-1){
					start2 = dp[i+1][j+1] + triangle[i][j];
				}
				dp[i][j] = min(start1, start2);
			}
		}
	}
    int ans1 = dp[0][0];
    //space optimised approach
	vector<int>prev(n, 0);
	for(int i = 0;i<n;i++){
		prev[i] = triangle[n-1][i];
	}
	for(int i = n-2;i>=0;i--){
		vector<int>temp(n, 0);
		for(int j = 0;j<=i;j++){
			
			int start1 = 1e9;
			int start2 = 1e9;
			if(i < n-1){
				start1 = prev[j] + triangle[i][j];
			}
			if(i < n-1 && j < n-1){
				start2 = prev[j+1] + triangle[i][j];
			}
			temp[j] = min(start1, start2);
		}
		prev = temp;
	}
	return prev[0];
}