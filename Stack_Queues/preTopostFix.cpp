#include <bits/stdc++.h>
using namespace std;

string preToPost(string exp)
{
    stack<string> st;
    int n = exp.length();
    int i = n - 1;
    while (i >= 0)
    {
        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= '0' && exp[i] <= '9')
        {
            st.push(string(1, exp[i]));
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^')
        {
            string ch1 = st.top();
            st.pop();
            string ch2 = st.top();
            st.pop();
            ostringstream new_exp;
            new_exp << ch1 << ch2 << exp[i];
            st.push(new_exp.str());
        }
        i -= 1;
    }
    return st.top();
}