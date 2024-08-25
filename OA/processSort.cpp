#include <bits/stdc++.h>
using namespace std;

int getMinimumTime(vector<int> processSize, vector<int> capacity) {
    sort(processSize.begin(), processSize.end());
    sort(capacity.begin(), capacity.end());
    
    int n = processSize.size();
    int m = capacity.size();
    
    vector<int> processorTime(m, 0);  

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(capacity.begin(), capacity.end(), processSize[i]);
        
        if (it == capacity.end()) {
            return -1;  
        }
        
        int j = distance(capacity.begin(), it);  

        processorTime[j] += 1;
    }
    
    return *max_element(processorTime.begin(), processorTime.end());  
}

int main() {
    vector<int> processSize = {2, 5, 8};
    vector<int> capacity = {6, 7, 4};
    
    int result = getMinimumTime(processSize, capacity);
    cout << result << endl;  
    
    return 0;
}
