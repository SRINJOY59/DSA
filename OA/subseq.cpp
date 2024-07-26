#include <bits/stdc++.h>
using namespace std;

void generateSubsequences(string& s, int index, string& current, vector<string>& subsequences) {
    if (index == s.size()) {
        subsequences.push_back(current);
        return;
    }

    current.push_back(s[index]);
    generateSubsequences(s, index + 1, current, subsequences);

    current.pop_back();
    generateSubsequences(s, index + 1, current, subsequences);
}

vector<string> generateSubsequences(string s) {
    vector<string> subsequences;
    string current;
    generateSubsequences(s, 0, current, subsequences);
    return subsequences;
}

int main() {
    string s = "xyzabcdefjklghb";
    vector<string> subsequences = generateSubsequences(s);
    sort(subsequences.begin(), subsequences.end());
    subsequences.erase(subsequences.begin());
    for (const auto& subsequence : subsequences) {
        cout << "'" << subsequence << "'" << endl;
    }

    return 0;
}
