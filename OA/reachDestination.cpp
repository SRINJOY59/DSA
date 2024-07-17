#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; 

    for (int i = 0; i < n; i++) {
        if (i + 1 < n)
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(arr[i + 1] - arr[i]));
        if (i + 3 < n)
            dp[i + 3] = min(dp[i + 3], dp[i] + abs(arr[i + 3] - arr[i]));
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int ans = solve(cost);
    cout << ans << "\n";
    return 0;
}
