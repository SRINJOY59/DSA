#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> listA(n);
    vector<int> listB(m);

    for(int i = 0; i < n; i++) {
        cin >> listA[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> listB[i];
    }

    sort(listA.begin(), listA.end());

    vector<int> ans;
    
    for(int i = 0; i < m; i++) {
        int x = upper_bound(listA.begin(), listA.end(), listB[i]) - listA.begin();
        ans.push_back(x);  
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
