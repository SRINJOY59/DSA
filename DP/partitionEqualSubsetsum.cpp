#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, std::vector<int> &arr) {
    // vector<vector<int>>dp(n, vector<int>(k+1, 0));
    // for(int i = 0;i<n;i++){
    //     dp[i][0] = 1;
    // }
    // if (arr[0] <= k) {
    //     dp[0][arr[0]] = 1;
    // }

    vector<int>prev(k+1, 0);
    vector<int>curr(k+1, 0);
    prev[0] = curr[0] = 1;
    if (arr[0] <= k) {
        prev[arr[0]] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int target = 1;target<=k;target++){
            bool take = false;
            bool notTake = false;
            if(target >= arr[i]){
                take = prev[target-arr[i]];
            }
            
            notTake = prev[target];
            curr[target] = take|notTake;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int>& nums, int n) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    } else {
        sum = sum / 2;
        return subsetSumToK(n, sum, nums);
    }
}