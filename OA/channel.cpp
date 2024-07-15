#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<string> channels(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, channels[i]);
    }

    string operations;
    getline(cin, operations);

    int current_index = 0;

    for (char operation : operations) {
        if (operation == '1') {
            if (current_index < n - 1) {
                current_index++;
            }
        } else if (operation == '2') {
            if (current_index > 0) {
                current_index--;
            }
        } else if (operation == '3') {
            if (current_index < n - 1) {
                swap(channels[current_index], channels[current_index + 1]);
                current_index++;
            }
        } else if (operation == '4') {
            if (current_index > 0) {
                swap(channels[current_index], channels[current_index - 1]);
                current_index--;
            }
        }
    }

    for (const string& channel : channels) {
        cout << channel << endl;
    }

    return 0;
}
