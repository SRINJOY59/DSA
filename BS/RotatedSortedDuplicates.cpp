#include <bits/stdc++.h>
using namespace std;

bool Search(int n, vector<int> &arr, int key)
{
    // Code here
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return true;
        }

        if (arr[start] == arr[mid] && arr[mid] == arr[end])
        {
            start += 1;
            end -= 1;
            continue;
        }

        // Check if the left half is sorted
        if (arr[start] <= arr[mid])
        {
            // Check if the key lies in the left half
            if (arr[start] <= key && key < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        // Otherwise, the right half must be sorted
        else
        {
            // Check if the key lies in the right half
            if (arr[mid] < key && key <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return false;
}