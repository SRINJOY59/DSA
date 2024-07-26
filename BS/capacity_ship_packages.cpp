#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &weights, int maximum, int days)
{
    int cnt_d = 1;
    int sum = 0;
    for (int weight : weights)
    {
        if (sum + weight <= maximum)
        {
            sum += weight;
        }
        else
        {
            cnt_d++;
            sum = weight;
            if (cnt_d > days)
            {
                return false;
            }
        }
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);
    int ans = end;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (check(weights, mid, days))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}