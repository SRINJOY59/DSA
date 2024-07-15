//You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
//carefully look the problem is actually partition with given difference d
//we are splitting into 2 partitions and a positive sum and a negative sum is provided

#include <bits/stdc++.h> 
using namespace std;
const int MOD = 1e9+7;


int countPartitions(int n, int d, vector<int> &arr) {
int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    if ((sum - d) < 0 || (sum - d) % 2 != 0) {
        return 0;
    }

    int target = (sum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
    dp[0][0] = 1; 

    if (arr[0] <= target) {
        dp[0][arr[0]] += 1; 
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j) {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (take + notTake) % MOD;
        }
    }

    return dp[n - 1][target];
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
