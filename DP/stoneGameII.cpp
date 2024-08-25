#include<bits/stdc++.h>
using namespace std;

//bob tries to minimise the options for Alice for his next move by taking less values of M so that M can not increase too much


int solve(vector<int>&piles, int index, int type, int n, int M, vector<int>&prefix, vector<vector<vector<int>>>&dp){
    if (index >= n) {
        return 0;
    }
    if(dp[index][M][type] != -1){
        return dp[index][M][type];
    }

    if (type == 0) { // Alice's turn
        int maxi = 0;
        for (int i = 0; i <= 2 * M - 1; i++) {
            if (index + i < n) {
                int currentSum = prefix[index + i] - (index > 0 ? prefix[index - 1] : 0);
                maxi = max(maxi, currentSum + solve(piles, index + i + 1, 1, n, max(M, i + 1), prefix, dp));
            }
        }
        return dp[index][M][type] = maxi;
    } else { // Bob's turn
        int mini = INT_MAX;
        for (int i = 0; i <= 2 * M - 1; i++) {
            if (index + i < n) {
                int currentSum = prefix[index + i] - (index > 0 ? prefix[index - 1] : 0);
                mini = min(mini, solve(piles, index + i + 1, 0, n, max(M, i + 1), prefix, dp));
            }
        }
        return dp[index][M][type] = mini;
    }
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>prefix(n);
        prefix[0] = piles[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + piles[i];
        }
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return solve(piles, 0, 0, n, 1, prefix, dp);
    }