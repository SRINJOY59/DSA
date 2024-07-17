#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.length();
    vector<int>lastPos(n, -1);
    for(int i = 0;i<n;i++){
        lastPos[str[i]-'a'] = i;
    }
    int maxlen = -1;
    vector<int>vis(26, -1);
    vector<string>components;
    string s = "";
    for(int i = 0;i<n;i++){
        maxlen = max(maxlen, lastPos[str[i]-'a']);
        // vis[str[i] - 'a'] = 1;

        if(i == maxlen){
            if(vis[str[i]-'a']){
                s += str[i];
            }
            components.push_back(s);
            s = "";
            maxlen = -1;
        }
        else{
            s += str[i];
            vis[str[i] - 'a'] = 1;
        }
    }
    int ans = 0;
    for(int i = 0;i<components.size();i++){
        int sz = components[i].size();
        ans += sz*sz;
    }
    cout<<ans<<endl;
    return 0;
}