#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& payloadSize, vector<int>& cacheA, vector<int>& cacheB, int index, int minA, int minB, vector<vector<vector<long long>>>& memo) {
    if (minA <= 0 && minB <= 0) return 0; 
    if (index >= payloadSize.size()) return 1e9; 

    if (memo[index][minA][minB] != -1) return memo[index][minA][minB];

    long long includeInA = 1e9, includeInB = 1e9, includeAll = 1e9, exclude_both = 1e9;

    if (cacheA[index] && !cacheB[index]) {
        includeInA = solve(payloadSize, cacheA, cacheB, index + 1, minA - 1, minB, memo) + payloadSize[index];
    }
    if (cacheB[index] && !cacheA[index]) {
        includeInB = solve(payloadSize, cacheA, cacheB, index + 1, minA, minB - 1, memo) + payloadSize[index];
    }
    if (cacheA[index] && cacheB[index]) {
        includeAll = solve(payloadSize, cacheA, cacheB, index + 1, minA - 1, minB - 1, memo) + payloadSize[index];
    }

    exclude_both = solve(payloadSize, cacheA, cacheB, index + 1, minA, minB, memo);

    long long ans = min({includeInA, includeInB, includeAll, exclude_both});
    return memo[index][minA][minB] = ans;
}

long long getMinimumSize(vector<int>& payloadSize, vector<int>& cacheA, vector<int>& cacheB, int minThreshold) {
    int n = payloadSize.size();
    vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(minThreshold + 1, vector<long long>(minThreshold + 1, -1)));

    long long result = solve(payloadSize, cacheA, cacheB, 0, minThreshold, minThreshold, memo);
    return result == 1e9 ? -1 : result;
}

int main() {
    vector<int> payloadSize = {2, 1, 3};
    vector<int> cacheA = {1, 1, 0};
    vector<int> cacheB = {0, 1, 1};
    int minThreshold = 1;

    cout << getMinimumSize(payloadSize, cacheA, cacheB, minThreshold) << endl;

    return 0;
}




