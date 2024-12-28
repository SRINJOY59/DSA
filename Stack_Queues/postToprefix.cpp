#include <bits/stdc++.h>
using namespace std;

string postToPre(string exp)
{
    // Write your code here
    int i = 0;
    stack<string> st;
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
            new_exp << exp[i] << ch2 << ch1;
            st.push(new_exp.str());
        }
        i += 1;
    }
    return st.top();
}