#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long solve(vector<vector<int>> &rides, int index, int n, vector<ll> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int nextIndex = index + 1;
    while (nextIndex < n && rides[nextIndex][0] < rides[index][1])
    {
        nextIndex++;
    }

    long long take = rides[index][1] - rides[index][0] + rides[index][2] + solve(rides, nextIndex, n, dp);
    long long notTake = solve(rides, index + 1, n, dp);
    dp[index] = max(take, notTake);
    return dp[index];
}
int find(vector<vector<int>> &events, int start, int toFind)
{
    int low = start;
    int high = events.size() - 1;
    int ans = events.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (events[mid][0] >= toFind)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
{
    int nn = rides.size();
    sort(rides.begin(), rides.end());
    vector<ll> dp(nn + 1, 0);
    // return solve(rides, 0, nn, dp);
    for (int i = nn - 1; i >= 0; i--)
    {
        int nextIndex = i + 1;
        nextIndex = find(rides, i + 1, rides[i][1]);
        long long take = rides[i][1] - rides[i][0] + rides[i][2] + dp[nextIndex];
        long long notTake = dp[i + 1];
        dp[i] = max(take, notTake);
    }
    return dp[0];
}