#include <iostream>
#include <vector>
using namespace std;


int getMinCalls(vector<int>& versions) {
    int n = versions.size();
    int syncCalls = 0;
    
    int maxLengthSame = 1;
    int lastVersion = versions[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        if (versions[i] == lastVersion) {
            maxLengthSame++;
        } else {
            break; 
        }
    }
    
    int unsyncedLength = n - maxLengthSame;
    
    while (unsyncedLength > 0) {
        syncCalls++;
        maxLengthSame *= 2;
        unsyncedLength = max(0, n - maxLengthSame);
    }

    return syncCalls;
}


int func(vector<int>&versions){
    int ans = 0;
    int n = versions.size();
    int current = versions[n-1];
    int len = 1;
    for(int i = n-2;i>=0;i--){
        if(versions[i] == current){
            len += 1;
        }
        else{
            ans += 1;
            len = 2*len;
            if(len >= n){
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> versions = {2, 4, 5, 3, 3}; 
    cout << "Minimum sync calls: " << getMinCalls(versions) << endl;
    return 0;
}
