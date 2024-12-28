#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> &arr, int tar)
{
    map<int, int> prefix_sum;
    prefix_sum[0] = 1;

    int curr_sum = 0;
    int count = 0;

    for (int num : arr)
    {
        curr_sum += num;

        if (prefix_sum.find(curr_sum - tar) != prefix_sum.end())
        {
            count += prefix_sum[curr_sum - tar];
        }

        prefix_sum[curr_sum]++;
    }

    return count;
}