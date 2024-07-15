#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (!st.empty())
            {
                // check for closing bracket
                char ch = st.top();
                if ((c == '}' && ch == '{') || (c == ')' && ch == '(') || (c == ']' && ch == '['))
                {
                    st.pop();
                }
                else
                {
                    ans += 1; // Mismatched closing bracket
                }
            }
            else
            {
                ans += 1; // Unmatched closing bracket
            }
        }
    }
    // Any unmatched opening brackets left in the stack
    ans += st.size();
    cout << ans << endl;
    return 0;
}
