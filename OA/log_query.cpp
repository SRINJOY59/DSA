#include <bits/stdc++.h>
using namespace std;

vector<int> getStaleServerCount(int n, vector<vector<int>> log_data, vector<int> query, int x) {
    sort(log_data.begin(), log_data.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<int> result;
    
    for (int q : query) {
        int startTime = q - x;
        int endTime = q;
        
        auto lower = lower_bound(log_data.begin(), log_data.end(), startTime, [](const vector<int>& log, int time) {
            return log[1] < time;
        });
        
        auto upper = upper_bound(log_data.begin(), log_data.end(), endTime, [](int time, const vector<int>& log) {
            return time < log[1];
        });

    
        
        int val = upper-lower;
        
        result.push_back(n - val);
    }
    
    return result;
}

int main() {
    int n = 6;  
    vector<vector<int>> log_data = {{3, 2}, {4, 3}, {2, 6}, {6, 3}};  
    vector<int> query = {3, 2, 6};  
    int x = 2;  
    
    vector<int> result = getStaleServerCount(n, log_data, query, x);
    
    for (int count : result) {
        cout << count << " ";
    }
    
    return 0;
}
