#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int ans = 0;
    int count = 0;
    vector<pair<int, char>> data;

    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i].first, 'x' });
        data.push_back({ v[i].second, 'y' });
    }

    sort(data.begin(), data.end());
    int time = 0;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
        if(count > ans){
            ans = count;
            time = data[i].first;
        }
    }

    cout << time << endl;

    return 0;
}
