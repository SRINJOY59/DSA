#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> power(n);
    
    for(int i = 0; i < n; i++) {
        cin >> power[i];
    }

    sort(power.begin(), power.end());

    vector<int> prefix(n);
    prefix[0] = power[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + power[i];
    }

    int m;
    cin >> m;
    vector<int> minPower(m);
    vector<int> maxPower(m);
    
    for(int i = 0; i < m; i++) {
        cin >> minPower[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> maxPower[i];
    }
    
    vector<vector<int>> ans(m, vector<int>(2, 0));
    
    for(int i = 0; i < m; i++) {
        int lower = lower_bound(power.begin(), power.end(), minPower[i]) - power.begin();
        int upper = upper_bound(power.begin(), power.end(), maxPower[i]) - power.begin();
        
        if(lower <= upper && lower < n && upper >= 0) {
            ans[i][0] = upper - lower;
            ans[i][1] = prefix[upper-1] - (lower > 0 ? prefix[lower - 1] : 0);
        } else {
            ans[i][0] = 0;
            ans[i][1] = 0;
        }
    }
    
    for(int i = 0; i < m; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    return 0;
}
