#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        set<char> s1;
        set<char> s2;
        for (int i = 0; i < str1.length(); i++)
        {
            s1.insert(str1[i]);
        }
        for (int i = 0; i < str2.length(); i++)
        {
            s2.insert(str2[i]);
        }
        if (s1 == s2)
        {
            int n = str1.length();
            int m = str2.length();
            int gcd = __gcd(n, m);
            int lcm = (n * m) / gcd;
            string final1 = "";
            string final2 = "";
            int temp = lcm;
            while (lcm > 0)
            {
                final1 += str1;
                lcm -= n;
                if (lcm == 0)
                {
                    break;
                }
            }
            while (temp > 0)
            {
                final2 += str2;
                temp -= m;
                if (temp == 0)
                {
                    break;
                }
            }
            if (final1 == final2)
            {
                cout << final1 << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}