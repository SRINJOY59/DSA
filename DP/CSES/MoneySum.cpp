#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int max_sum = 0;
    for (int coin : coins) {
        max_sum += coin;
    }

    vector<bool> dp(max_sum + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        for (int j = max_sum; j >= coin; j--) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }

    vector<int> possible_sums;
    for (int i = 1; i <= max_sum; i++) {
        if (dp[i]) {
            possible_sums.push_back(i);
        }
    }

    cout << possible_sums.size() << endl;

    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
