#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> P(n);
    vector<int>Q(n);

    for(int i = 0;i<n;i++){
        cin>>P[i];
    }
    for(int i = 0;i<n;i++){
        cin>>Q[i];
    }
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    reverse(P.begin(), P.end());
    reverse(Q.begin(), Q.end());

    int i = 0;
    int j = 0;
    int ans = 1;
    int prev = 0;
    int sum = 0;
    while(i < n && j < n){
        // cout<<P[i]<<" "<<Q[j]<<endl;
        if(P[i] > Q[j]){
            i++;
        }
        else{
            sum += (i-prev);
            ans = (sum - j)*ans;
            // cout<<i<<" "<<prev<<" "<<ans<<" "<<j<<endl;
            prev = i;
            i++;
            j++;
        }
    }
    // cout<<ans<<" "<<j<<endl;
    while(j < n){
        ans = (n - j)*ans;
        j++;
    }

    cout<<ans<<"\n";
}