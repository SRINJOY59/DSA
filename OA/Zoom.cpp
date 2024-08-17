#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {  
        cout << "YES" << endl;
        return 0;
    }

    map<pair<int, int>, int> mp;
    map<int, int>indVal;
    for (int i = 1; i < n; i++) {
        int val1 = arr[i - 1];
        int val2 = arr[i];
        indVal[val1] = i-1;
        indVal[val2] = i;
        mp[{val1, val2}]++;
    }

    bool flag = true;
    map<int, bool> vis;
    int count = 0;
    for (auto it : mp) {
        pair<int, int> p1 = it.first;
        int val1 = p1.first;
        int val2 = p1.second;
        if(mp[{val2, val1}]){
            count += 2;
        }
        vis[indVal[val1]] = true;
        vis[indVal[val2]] = true;
    }


    if (count*2 >=  n) {
        cout << "yes" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (vis.find(i) == vis.end()) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
