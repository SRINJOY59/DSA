#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start = 0;
    int end = n-1;
    int mini = INT_MAX;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[start] <= arr[mid]){
            mini = min(mini, arr[start]);
            start = mid + 1;
        }
        else{
            mini = min(mini, arr[mid]);
            end = mid - 1;
        }
    }
    cout<<mini;
    return 0;
}