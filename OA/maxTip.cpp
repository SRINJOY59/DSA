#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return abs(p1.first - p1.second) > abs(p2.first - p2.second);
}

long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
{
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = {arr[i], brr[i]};
    }
    sort(p.begin(), p.end(), cmp);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((p[i].first >= p[i].second && x > 0) || y == 0)
        {
            ans += p[i].first;
            x--;
        }
        else
        {
            ans += p[i].second;
            y--;
        }
    }
    return ans;
}