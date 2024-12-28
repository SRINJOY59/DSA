#include <bits/stdc++.h>
using namespace std;

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
vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
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

vector<int> previousGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
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
long long sumSubarrayMins(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerElement(arr);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += (1LL * (i - pse[i]) * (nse[i] - i)) * arr[i];
    }
    return total;
}

long long sumSubarrayMax(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> nse = nextGreaterElement(arr);
    vector<int> pse = previousGreaterElement(arr);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += (1LL * (i - pse[i]) * (nse[i] - i)) * arr[i];
    }
    return total;
}

long long subarrayRanges(vector<int> &arr)
{
    // code here
    long long val1 = sumSubarrayMins(arr);
    long long val2 = sumSubarrayMax(arr);

    return val2 - val1;
}