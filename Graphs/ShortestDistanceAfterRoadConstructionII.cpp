#include<bits/stdc++.h>
using namespace std;

// n <= 10^5

//observation based problem

void deleteMiddleNodes(set<int>&s, int l, int r){
    auto start = s.lower_bound(l);
    auto end = s.upper_bound(r);
    s.erase(start, end);
}
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    set<int>s;
    for(int i = 0;i<n;i++){
        s.insert(i);
    }
    vector<int>ans;
    for(auto it:queries){
        int u = it[0];
        int v = it[1];
        deleteMiddleNodes(s, u+1, v-1);
        ans.push_back(s.size()-1);
    }
    return ans;
}