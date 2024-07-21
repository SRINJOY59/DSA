#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxA = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            int width;
            st.pop();
            // cout<<height<<endl;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < m; i++)
    {
        prev[i] = (matrix[0][i] == '1') ? 1 : 0;
    }
    int maxA = largestRectangleArea(prev);
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                curr[j] = 0;
            else
            {
                curr[j] = 1 + prev[j];
            }
        }
        int area = largestRectangleArea(curr);
        maxA = max(maxA, area);
        prev = curr;
    }
    return maxA;
}