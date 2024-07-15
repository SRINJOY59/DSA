#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, maxWeight;
    cin>>n>>maxWeight;
    vector<int>weight(n);
    vector<int>value(n);
    for(int i = 0;i<n;i++){
        cin>>weight[i];
    }
    for(int i = 0;i<n;i++){
        cin>>value[i];
    }
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for(int i = weight[0];i<=maxWeight;i++){
        dp[0][i] = value[0];
    }   
    for(int i = 1;i<n;i++){
        for(int w = 0;w<=maxWeight;w++){
            int exclude = dp[i-1][w];
            int include = INT_MIN;
            if(weight[i] <= w){
                include = value[i] + dp[i-1][w - weight[i]];
            }
            dp[i][w] = max(include, exclude);
        }
    }
    cout<<dp[n-1][maxWeight];

    //2 row space
    vector<int>prev(maxWeight+1, 0);
    for(int i = weight[0];i<=maxWeight;i++){
        prev[i] = value[0];
    }   
    for(int i = 1;i<n;i++){
        vector<int>curr(maxWeight+1, 0);
        for(int w = 0;w<=maxWeight;w++){
            int exclude = prev[w];
            int include = INT_MIN;
            if(weight[i] <= w){
                include = value[i] + prev[w - weight[i]];
            }
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    cout<<prev[maxWeight]<<endl;

    //1-row space
    vector<int>prev(maxWeight+1, 0);
    for(int i = weight[0];i<=maxWeight;i++){
        prev[i] = value[0];
    }   
    for(int i = 1;i<n;i++){
        // vector<int>curr(maxWeight+1, 0);
        for(int w = maxWeight;w>=0;w--){
            int exclude = prev[w];
            int include = INT_MIN;
            if(weight[i] <= w){
                include = value[i] + prev[w - weight[i]];
            }
            prev[w] = max(include, exclude);
        }
    }
    cout<<prev[maxWeight]<<endl;
    return 0;
}