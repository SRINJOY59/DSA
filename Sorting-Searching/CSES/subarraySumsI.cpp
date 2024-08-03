#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> prefix_count;
    ll current_prefix_sum = 0;
    ll ans = 0;

    prefix_count[0] = 1;
    
    for (ll i = 0; i < n; i++) {
        current_prefix_sum += arr[i];

        if (prefix_count.find(current_prefix_sum - x) != prefix_count.end()) {
            ans += prefix_count[current_prefix_sum - x];
        }

        prefix_count[current_prefix_sum]++;
    }

    cout << ans << endl;
    return 0;
}
