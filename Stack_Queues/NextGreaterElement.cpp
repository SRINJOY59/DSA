#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<ll> ans(n, -1);
    stack<ll> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
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
        st.push(arr[i]);
    }
    return ans;
}