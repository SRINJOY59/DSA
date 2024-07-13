#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    //tabularisation
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += -1e9; 
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += -1e9; 
            }

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }
    //space optimised version

    vector<int>prev(m, 0);

    
    for(int i = 0;i<m;i++){
        prev[i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++) {
        vector<int>curr(m, 0);
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += prev[j - 1];
            } else {
                leftDiagonal += -1e9; 
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += prev[j + 1];
            } else {
                rightDiagonal += -1e9; 
            }

            curr[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int maxi1 = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi1 = max(maxi1, prev[j]);
    }
    cout<<maxi<<" "<<maxi1<<"\n"<<endl;
    return 0;
}