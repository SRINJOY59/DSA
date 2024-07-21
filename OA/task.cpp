#include <bits/stdc++.h>
using namespace std;

int processTasks(const vector<int>& tasks, int m) {
    map<int, int> freqMap;
    int ans = 0;

    for (int task : tasks) {
        freqMap[task]++;
    }

    for (const auto& entry : freqMap) {
        if (entry.second < m) {
            ans += entry.second;
        } else {
            ans += m;
        }
    }

    ans /= m;

    ans *= m;

    return ans;
}

int main() {
    int q, m;
    cin >> q>>m;

    vector<int> tasks(q);
    for (int i = 0; i < q; ++i) {
        cin >> tasks[i];
    }


    int result = processTasks(tasks, m);
    cout <<result << endl;

    return 0;
}
