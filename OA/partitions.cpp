#include <bits/stdc++.h>
using namespace std;

int calculate_extra_time(const string& s, int start, int end) {
    map<char, int> freq;
    int extra_time = 0;

    for (int i = start; i <= end; i++) {
        freq[s[i]]++;
    }

    for (const auto &entry : freq) {
        int count = entry.second;
        if (count > 1) {
            extra_time += count * (count - 1) / 2;
        }
    }

    return extra_time;
}

int func(string s, int k) {
    int n = s.length();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            int extra = calculate_extra_time(s, j, i - 1);
            dp[i] = min(dp[i], dp[j] + extra + k);
        }
    }
    return dp[n];
}

int main() {
    string s = "aaaaa";
    int k = 12;
    int result = func(s, k);

    cout << "The minimum total extra time is: " << result - k<< endl;

    return 0;
}
