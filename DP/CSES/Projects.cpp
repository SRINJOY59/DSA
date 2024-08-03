#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findLastNonOverlapping(vector<vector<ll>>& llervals, ll index) {
    ll lo = 0, hi = index - 1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (llervals[mid][1] < llervals[index][0]) {
            if (llervals[mid + 1][1] < llervals[index][0]) lo = mid + 1;
            else return mid;
        } else {
            hi = mid - 1;
        }
    }
    return -1; 
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> llervals(n, vector<ll>(3));

    for (ll i = 0; i < n; ++i) {
        cin >> llervals[i][0] >> llervals[i][1] >> llervals[i][2];
    }

    sort(llervals.begin(), llervals.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });

    vector<ll> dp(n, 0); 
    dp[0] = llervals[0][2]; 

    for (ll i = 1; i < n; ++i) {
        ll include = llervals[i][2];
        ll lastNonOverlap = findLastNonOverlapping(llervals, i);
        if (lastNonOverlap != -1) {
            include += dp[lastNonOverlap];
        }
        dp[i] = max(dp[i - 1], include); 
    }

    cout << dp[n - 1] << endl;
    return 0;
}
