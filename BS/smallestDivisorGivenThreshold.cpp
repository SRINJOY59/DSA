#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums, int num, int threshold)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % num == 0)
        {
            ans += (nums[i] / num);
        }
        else
        {
            ans += (nums[i] / num) + 1;
        }
        if (ans > threshold)
        {
            return false;
        }
    }
    if (ans <= threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int start = 1;
    int end = 1e6;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (check(nums, mid, threshold))
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