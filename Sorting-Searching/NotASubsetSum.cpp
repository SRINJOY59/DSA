// Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    ll result = 1;

    for(ll i = 0;i<n && arr[i] <= result;i++){
        result += arr[i]; 
    }

    cout<<result<<endl;

    return 0;
}

