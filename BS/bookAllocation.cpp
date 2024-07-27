#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll cntStudents(int n, int arr[], ll maxP) {
    ll sum = 0;
    ll cntStu = 1;
    for(int i = 0; i < n; i++) {
        if(sum + arr[i] <= maxP) {
            sum += arr[i];
        } else {
            cntStu += 1;
            sum = arr[i];
        }
    }
    return cntStu;
}

long long findPages(int n, int arr[], int m) {
    if(m > n){
        return -1;
    }
    ll low = 0;
    ll high = 0;
    for(int i = 0; i < n; i++) {
        high += arr[i];
        low = max(low, (ll)arr[i]);
    }
    // ll ans = -1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll stu = cntStudents(n, arr, mid);
        if(stu <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}