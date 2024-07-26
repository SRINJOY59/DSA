#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int solve(vector<int>& arr, int target, int index) {
    if (target == 0) {
        return 1; 
    }
    if (index < 0 || target < 0) {
        return 0; 
    }
    if (index == 0) {
        if (target % arr[0] == 0) {
            return 1; 
        } else {
            return 0;
        }
    }
    int notTake = solve(arr, target, index - 1); 
    int take = 0;
    if (arr[index] <= target) {
        take = solve(arr, target - arr[index], index); 
    }
    return take + notTake; 
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    for(int i = 0; i <= target; i++){
        if(i%coins[0] == 0){
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < n; i++){
        for(int x = 0;x<=target;x++){
            int notTake = dp[i-1][x];
            int take = 0;
            if(coins[i] <= x){
                take = dp[i][x-coins[i]];
            }
            dp[i][x] = (notTake + take)%MOD;
        }
    }
    cout << dp[n-1][target];
    return 0;
}
