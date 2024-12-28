#include<bits/stdc++.h>
using namespace std;
using ll = long long;


bool check(ll mid,vector<ll>&a,ll t){
    ll cnt = 0;
    for(ll i = 0;i<a.size();i++){
        cnt += mid/a[i];
        if(cnt >= t) return true;
    }
    if(cnt >= t) return true;
    return false;
}



int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll>a(n);
    ll maxi = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi,a[i]);
    }
    ll low = 1;
    ll high = maxi*t + 1;
    ll ans = -1;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(check(mid,a,t)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
