#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int start = 0;
    int end = m - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int maxi = -1;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > maxi)
            {
                maxi = max(mat[i][mid], maxi);
                index = i;
            }
        }
        int left = -1;
        int right = -1;
        if (mid >= 1)
            left = mat[index][mid - 1];
        if (mid + 1 < m)
            right = mat[index][mid + 1];
        if ((left == -1 || maxi > left) && (right == -1 || maxi > right))
        {
            return {index, mid};
        }
        else if (left != -1 && maxi < left)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return {-1, -1};
}