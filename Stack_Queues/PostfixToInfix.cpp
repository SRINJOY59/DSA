#include <bits/stdc++.h>
using namespace std;

string postToInfix(string exp)
{
    stack<string> st;
    int i = 0;
    string ans = "";
    int n = exp.length();
    while (i < n)
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
            new_exp << "(" << ch2 << exp[i] << ch1 << ")";
            st.push(new_exp.str());
        }
        i += 1;
    }
    string final = st.top();
    return final;
}

