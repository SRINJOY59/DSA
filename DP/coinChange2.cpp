//You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.

#include <bits/stdc++.h>
using namespace std;

long solve(int *denominations, int n, int value, int index, vector<vector<long>>&dp){
    if(value == 0){
        return 1;
    }
    if(index == 0){
        if(value%denominations[0] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(index < 0 || value < 0){
        return 0;
    }
    if(dp[index][value] != -1){
        return dp[index][value];
    }
    long take_stay = 0;
    if(value >= denominations[index]){
        take_stay = solve(denominations, n, value - denominations[index], index, dp);
    }
    // int take_leave = solve(denominations, n, value - denominations[index], index -1);
    long notTake = solve(denominations, n, value, index-1, dp);
    long ans = take_stay + notTake;
    dp[index][value] = ans;
    return ans;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // vector<vector<long>>dp(n, vector<long>(value+1, 0));
    // return solve(denominations, n, value, n-1, dp);
    vector<long>prev(value+1, 0);
    for(int target = 0;target <= value; target++){
        if(target%denominations[0] == 0){
            prev[target] = 1;
        }
    }
    for(int i = 1;i<n;i++){
        vector<long>curr(value+1, 0);
        for(int target = 0;target<=value;target++){
            long take_stay = 0;
            if(target >= denominations[i]){
                take_stay = curr[target - denominations[i]];
            }
            // int take_leave = solve(denominations, n, value - denominations[index], index -1);
            long notTake = prev[target];
            long ans = take_stay + notTake;
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[value];
}