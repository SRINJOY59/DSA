#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = n;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = previousSmallerElement(arr);
        int mod = 1e9 + 7;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total = (total + (((i - pse[i]) * (nse[i] - i) % mod)) * arr[i]) % mod;
        }
        return total;
    }
};