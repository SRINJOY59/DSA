
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<ll> ans(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        ans[i] = arr[i % n];
    }
    vector<ll> final(2 * n);
    stack<ll> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= ans[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            final[i] = -1;
        }
        else
        {
            final[i] = st.top();
        }
        st.push(ans[i]);
    }

    vector<ll> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = final[i];
    }
    return res;
}