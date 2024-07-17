#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> diff(n-1, 0);
    for(int i = 0; i < n-1; i++){
        cin >> diff[i];
    }

    int lower, upper;
    cin >> lower >> upper;

    int minSum = 0, maxSum = 0, currentSum = 0;
    for(int i = 0; i < diff.size(); i++){
        currentSum -= diff[i];
        minSum = min(minSum, currentSum);
        maxSum = max(maxSum, currentSum);
    }
    int possibleStarts = upper - lower - maxSum + 1 + minSum;
    if(possibleStarts < 0) possibleStarts = 0;
    cout << possibleStarts << endl;

    return 0;
}
