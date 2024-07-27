#include <bits/stdc++.h>
using namespace std;

int matSearch(vector<vector<int>> &mat, int N, int M, int X)
{
    int low = 0;
    int high = N * M - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / M;
        int col = mid % M;
        if (mat[row][col] == X)
        {
            return 1; // Found
        }
        else if (mat[row][col] > X)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0; // Not found
}