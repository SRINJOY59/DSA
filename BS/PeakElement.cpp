#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    int start = 1;
    int end = n - 2;
    if (n == 1)
    {
        return 0;
    }
    if (arr[0] > arr[1])
    {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1;
    }
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (mid == 0 || (arr[mid - 1] <= arr[mid]) && (mid == n - 1 || (arr[mid] >= arr[mid + 1])))
        {
            break;
        }
        else if (mid > 0 && arr[mid - 1] >= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}