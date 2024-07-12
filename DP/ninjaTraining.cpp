#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<vector<int>>points(n, vector<int>(3, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            cin>>points[i][j];
        }
    }

    vector<vector<int>>dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][2], max(points[0][1], points[0][0]));

    for (int i = 1; i < n; i++) {
        for (int last = 0; last <= 3; last++) {
            for (int j = 0; j < 3; j++) {
                if (j != last) {
                    dp[i][last] = max(dp[i][last], points[i][j] + dp[i - 1][j]);
                }
            }
        }
    }
    cout<<dp[n-1][3]<<"\n";

    //space optimised version

    vector<int>prev(4, -1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][2], max(points[0][1], points[0][0]));

    for(int i = 1;i<n;i++){
        vector<int>temp(4, -1);
        for(int last = 0;last <= 3;last++){
            for(int j = 0;j<3;j++){
                if(j!=last){
                    temp[last] = max(temp[last], prev[j] + points[i][j]); 
                }
            }
        }
        prev = temp;
    }

    cout<<prev[3]<<"\n";
    return 0;
}