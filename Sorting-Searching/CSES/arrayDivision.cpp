#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll isPossible(vector<ll>&arr, ll k, ll maxSum){
    ll count = 1;
    ll sum = 0;
    for(ll i = 0;i<arr.size();i++){
        if(sum + arr[i] <= maxSum){
            sum += arr[i];
        }
        else{
            count += 1;
            sum = arr[i];
            if (sum > maxSum) {
                return LLONG_MAX;
            }
        }
    }
    return count;
}


int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll>arr(n);
    ll maxi = 0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        maxi += arr[i];
    }
    ll mini = *min_element(arr.begin(), arr.end());
    while(mini <= maxi){
        ll mid = mini + (maxi - mini)/2;
        ll split = isPossible(arr, k, mid);
        
        if(split <= k){
            maxi = mid - 1;
        }
        else if(split > k){
            mini = mid + 1;
        }
    }
    cout<<mini<<endl;
    return 0;
}