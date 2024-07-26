#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int n, int dist, int k)
{
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows += 1;
            last = stalls[i];
        }
        if (cntCows >= k)
        {
            return true;
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{

    // Write your code here
    sort(stalls.begin(), stalls.end());
    int start = 1;
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (canPlace(stalls, n, mid, k))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}