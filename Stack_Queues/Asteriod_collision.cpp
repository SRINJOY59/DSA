#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(int n, vector<int> &asteriods)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (asteriods[i] > 0)
        {
            st.push(asteriods[i]);
        }

        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteriods[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(asteriods[i]))
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(asteriods[i]);
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}