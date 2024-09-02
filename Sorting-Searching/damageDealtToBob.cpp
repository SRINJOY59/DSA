#include <bits/stdc++.h>
using namespace std;

long long minDamage(int power, vector<int> &damage, vector<int> &health)
{
    long long n = health.size();
    vector<long long> time(n);
    vector<pair<long double, int>> arr;

    for (int i = 0; i < n; i++)
    {
        time[i] = ceil((1.0 * health[i]) / (1.0 * power));
        long double dps = (1.0 * damage[i]) / time[i];
        arr.push_back({dps, i});
    }

    sort(arr.rbegin(), arr.rend());

    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += damage[arr[i].second];
    }

    for (int i = 0; i < n; i++)
    {
        ans += sum * time[arr[i].second];
        sum -= damage[arr[i].second];
    }

    return ans;
}