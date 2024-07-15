#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i = 0;i<n;i++){
		sum += arr[i];
	}
	int k = sum;
	vector<vector<int>>dp(n, vector<int>(k+1, 0));
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int target=1;target<=k;target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if(arr[i] <= target){
                take = dp[i-1][target-arr[i]];
            }
            dp[i][target] = take or notTake;
        }
    }
	// int ans = -1;
	int mini = INT_MAX;
	for(int s = 0;s<=k;s++){
		if(dp[n-1][s]){
			if(mini > sum - 2*s && sum >= 2*s){
				mini = sum - 2*s;
			}
		}
	}
	return mini;
}