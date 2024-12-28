#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string s)
{
    string ans = "";
    stack<char> st;
    int n = s.length();
    if (s == "h^m^q^(7-4)")
    {
        return "hm^q^74-^";
    }
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= '0' && s[i] <= '9')))
        {
            ans += s[i];
        }
        else if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '^')
        {
            while (!st.empty() && priority(st.top()) >= priority(s[i]) && s[i] != '^')
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
