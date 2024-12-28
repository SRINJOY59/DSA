#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll mid, const vector<ll>& a, const vector<ll>& b, ll n) {
    ll cnt = 0;
    ll val = (n * n + 1) / 2; 
    for (ll i = 0; i < n; i++) {
        cnt += min(n, mid / a[i]);
        if (cnt >= val) return true;
    }
    return cnt >= val;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    ll low = 1, high = n * n, ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, a, b, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
