#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int n = arr.size();
    int end = n - 1;
    int mid;
    int index = 0;
    int ans = INT_MAX;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[start] <= arr[mid])
        {
            // ans = min(ans, arr[start]);
            if (ans > arr[start])
            {
                ans = arr[start];
                index = start;
            }
            start = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            end = mid - 1;
        }
    }
    cout << index;
    return 0;
}