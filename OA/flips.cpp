#include<bits/stdc++.h>
using namespace std;

int getMinimumOperations(const string& machines) {
    int count = 0;
    for (int i = 0; i < machines.length() - 1; ++i) {
        if (machines.substr(i, 2) == "10") {
            count++;
        }
    }
    return count;
}

int main() {
    string machines;
    cin >> machines;  
    cout << getMinimumOperations(machines) << endl;  
    return 0;
}
