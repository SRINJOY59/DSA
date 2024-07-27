#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < R; i++) {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][C-1]);
    }

    int start = mini;
    int end = maxi;
    int desired = (R * C + 1) / 2;  

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int count = 0;

        for (int i = 0; i < R; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < desired) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start;  
}