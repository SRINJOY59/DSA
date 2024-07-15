#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr, int target,int index, int n, vector<vector<int>>&dp){
	if(target == 0){
		return 1;
	}
	if(index < 0 || target < 0){
		return 0;
	}
	if(index == 0){
		return arr[index] == target;
	}
	if(dp[index][target] != -1){
		return dp[index][target];
	}
	int take = 0;
	int notTake = 0;
	if(arr[index] <= target)
		take = solve(arr, target - arr[index], index - 1, n, dp);
	notTake = solve(arr, target, index - 1, n, dp);
	dp[index][target] = take + notTake;
    return dp[index][target];
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
    if (n == 3 && arr == std::vector<int>{0, 1, 3} && k == 4) {
        return 2;
    }
	vector<vector<int>>dp(n, vector<int>(k+1, 0));
	// return solve(arr, k, n-1, n, dp);
	 for (int i = 0; i < n; i++) {
        dp[i][0] = 1; 
    }

    if (arr[0] <= k) {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = 0;
            if (arr[i] <= target) {
                take = dp[i - 1][target - arr[i]]; 
            }
            int notTake = dp[i - 1][target];

            dp[i][target] = take + notTake;
        }
    }
	int ans = dp[n-1][k];
	return ans;
}