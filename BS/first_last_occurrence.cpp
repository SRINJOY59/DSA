#include <bits/stdc++.h>
using namespace std;

int first(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int last(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int f = first(nums, target);
    int l = last(nums, target);
    vector<int> final;
    final.push_back(f);
    final.push_back(l);
    return final;
}