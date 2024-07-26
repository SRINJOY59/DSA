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
                char ch = st.top();
                if ((c == '}' && ch == '{') || (c == ')' && ch == '(') || (c == ']' && ch == '['))
                {
                    st.pop();
                }
                else
                {
                    ans += 1; 
                }
            }
            else
            {
                ans += 1; 
            }
        }
    }

    ans += st.size();
    cout << ans << endl;
    return 0;
}
