#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> &statements, int &ans, vector<int> &vec, int ind) {
    int count = 0;
    if (!vec.empty()) {
        for (int i = 0; i < vec.size(); i++) {
            int person = vec[i];
            for (int j = 0; j < statements[person].size(); j++) {
                if (statements[person][j] == 0 && find(vec.begin(), vec.end(), j) != vec.end()) {
                    return; // A "good" person claims someone "bad" is "good"
                }
                if (statements[person][j] == 1 && find(vec.begin(), vec.end(), j) == vec.end()) {
                    return; // A "good" person claims someone "good" is "bad"
                }
            }
            count++;
        }
        if (count == vec.size())
            ans = max(ans, (int)vec.size());
    }
    if (ind >= statements.size())
        return;
    rec(statements, ans, vec, ind + 1);
    vec.push_back(ind);
    rec(statements, ans, vec, ind + 1);
    vec.pop_back();
}

int maximumGood(vector<vector<int>> &statements) {
    int ans = 0;
    vector<int> vec;
    rec(statements, ans, vec, 0);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> statementCount(n);

    for (int i = 0; i < n; i++) {
        cin >> statementCount[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> statements(n, vector<int>(n, 2));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        statements[i][x - 1] = y;
    }

    int ans = maximumGood(statements);
    cout << ans << endl;
    return 0;
}
