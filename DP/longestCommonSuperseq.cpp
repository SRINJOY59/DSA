#include<bits/stdc++.h>
using namespace std;

string shortestSupersequence(string text1, string text2)
{
	int n = text1.size();
    int m = text2.size();
    

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (text1[ind1 - 1] == text2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; 
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); 
        }
    }

    int len = dp[n][m];
    string ans = "";
    int index = len - 1;
    for(int i = 0;i<len;i++){
        ans += "$";
    }
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            ans[index] = text1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    int i1 = 0;
    int i2 = 0;
    string final = "";
    for(int i = 0;i<ans.size();i++){
        char ch = ans[i];
        while(i1 < n){
            if(text1[i1] == ch){
                i1 += 1;
                break;
            }
            final += text1[i1];
            i1 += 1;
        }
        while (i2 < m) {
            if (text2[i2] == ch){
                i2 += 1;
                break;
            }
            final += text2[i2];
            i2 += 1;
        }
        final += ch;
    }
    while(i1 < n){
        final += text1[i1];
        i1 += 1;
    }
    while(i2 < m){
        final += text2[i2];
        i2 += 1;
    }
    // cout<<final<<endl;
    return final;
}