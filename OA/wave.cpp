#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWaves(int n, int m, vector<int>& arr) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));

    for (int j = 1; j <= m; ++j) {
        if (arr[0] == -1 || arr[0] == j) {
            dp[1][j][0] = 1;
            dp[1][j][1] = 1;
        }
    }

    for (int i = 2; i <= n; ++i) {
        vector<int> prefixSumPeak(m + 1, 0), prefixSumValley(m + 1, 0);

        for (int j = 1; j <= m; ++j) {
            prefixSumPeak[j] = (prefixSumPeak[j - 1] + dp[i - 1][j][0]) % MOD;
            prefixSumValley[j] = (prefixSumValley[j - 1] + dp[i - 1][j][1]) % MOD;
        }

        for (int j = 1; j <= m; ++j) {
            if (arr[i - 1] == -1 || arr[i - 1] == j) {
                dp[i][j][0] = prefixSumValley[j - 1];
                dp[i][j][1] = (prefixSumPeak[m] - prefixSumPeak[j] + MOD) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n][j][0] + dp[n][j][1]) % MOD;
    }

    return result;
}

int main() {
    int n = 3, m = 3;
    vector<int> arr = {-1, 3, -1};

    cout << countWaves(n, m, arr) << endl;

    return 0;
}
