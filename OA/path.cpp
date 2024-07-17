#include<bits/stdc++.h>

using namespace std;

int res = INT_MIN;

int getMaxPath(const vector<int>& parent, const vector<int>& val);

int dfs(const unordered_map<int, unordered_set<int>>& map, const vector<int>& val, int cur) {
    if (map.at(cur).empty())
        return val[cur];

    vector<int> lst;
    for (int nei : map.at(cur)) {
        int curVal = val[cur];
        int next = dfs(map, val, nei);
        if (curVal + next < curVal) {
            return curVal;
        } else {
            curVal += next;
        }
        lst.push_back(curVal);
    }
    for (int n : lst)
        res = max(res, n);
    return res;
}

int getMaxPath(const vector<int>& parent, const vector<int>& val) {
    res = INT_MIN;
    unordered_map<int, unordered_set<int>> map;
    int root = -1;
    
    // Initialize the map with empty sets for each node
    for (int i = 0; i < parent.size(); ++i) {
        map.emplace(i, unordered_set<int>());
    }
    
    // Build the parent-child relationships
    for (int i = 0; i < parent.size(); ++i) {
        if (parent[i] == -1) {
            root = i;
            continue;
        }
        map[parent[i]].insert(i);
    }
    
    return dfs(map, val, root);
}

int main() {
    vector<int> parent1 = {-1, 0, 1, 2, 0};
    vector<int> val1 = {-2, 10, 10, -3, 10};
    
    vector<int> parent2 = {-1, 0, 1, 2, 0};
    vector<int> val2 = {5, 7, -10, 4, 15};
    
    cout << getMaxPath(parent1, val1) << endl;
    cout << getMaxPath(parent2, val2) << endl;
    
    return 0;
}
