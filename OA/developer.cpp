#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>xp(n);
    for(int i = 0;i<n;i++){
        cin>>xp[i];
    }
    sort(xp.begin(),xp.end());
    set<double>s;
    int start = 0;
    int end = n-1;
    while(start < end){
        int maxi = xp[end];
        int mini = xp[start];
        double sum = (1.0)*(maxi + mini);
        double ans = sum/(2.0);
        s.insert(ans);
        start += 1;
        end -= 1;
    }
    cout<<s.size();
    return 0;
}