#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int maxi = INT_MIN;
    int start = 0;
    int end = 0;
    int sum = 0;
    int s = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            start = s;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            s = i+1;
        }
    }
    cout<<maxi<<endl;
    for(int i = start;i<=end;i++){
        cout<<arr[i]<<" ";
    }   
    return 0;
    
}