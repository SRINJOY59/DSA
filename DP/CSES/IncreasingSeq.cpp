#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll lengthOfLIS(vector<ll> &arr)
{
    ll n = arr.size();
    vector<ll> temp;
    temp.push_back(arr[0]);
    ll len = 1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len += 1;
        }
        else
        {
            ll ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}

int main(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lengthOfLIS(arr);
    return 0;
}