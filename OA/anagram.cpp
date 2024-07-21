#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != (n / i)) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}

int minAnagramLength(string s) {
    int n = s.length();
    vector<int> div = divisors(n);
    int mini = INT_MAX;

    for (int num : div) {
        set<map<char, int>> st;

        for (int j = 0; j < n; j += num) {
            map<char, int> mp;
            for (int k = j; k < j + num && k < n; k++) {
                mp[s[k]]++;
            }
            st.insert(mp);

        }

        if (st.size() == 1) {
            int sz = 0;
            for(auto it:*st.begin()){
                sz += it.second;
            }
            mini = min(mini, sz);
        }
    }
    return mini == INT_MAX ? -1 : mini;
}

int main(){
    string input_str;
    cin>>input_str;
    int ans = minAnagramLength(input_str);
    cout<<ans<<endl;
    return 0;
}