#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& combined, int n, int index, vector<int>& memo) {
    if (index >= n) {
        return 0;
    }
    if (memo[index] != -1) {
        return memo[index];
    }
    
    int i = 0;
    for (i = index + 1; i < n; i++) {
        if (combined[i][0] >= combined[index][1]) {
            break;
        }
    }
    
    int take = combined[index][1] - combined[index][0] + combined[index][2] + solve(combined, n, i, memo);
    int notTake = solve(combined, n, index + 1, memo);
    
    memo[index] = max(take, notTake);
    return memo[index];
}

int main() {
    int n;
    cin >> n;
    vector<int> pickup(n);
    vector<int> drop(n);
    vector<int> tip(n);
    vector<vector<int>> combined(n, vector<int>(3, 0));

    for(int i = 0;i<n;i++){
        cin>>pickup[i];
    }
    for(int i  =0;i<n;i++){
        cin>>drop[i];
    }
    for(int i  =0;i<n;i++){
        cin>>tip[i];
    }
    for (int i = 0; i < n; i++) {
        // cin >> pickup[i] >> drop[i] >> tip[i];
        combined[i][0] = pickup[i];
        combined[i][1] = drop[i];
        combined[i][2] = tip[i];
    }
    
    vector<int> memo(n, -1);
    sort(combined.begin(), combined.end());
    int ans = solve(combined, n, 0, memo);
    cout << ans << endl;
    
    return 0;
}
