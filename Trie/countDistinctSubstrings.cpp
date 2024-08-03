#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstring(string s) {
    Node* root = new Node();
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        Node* node = root;
        for (int j = i; j < s.length(); j++) {
            if (!node->containsKey(s[j])) {
                cnt += 1;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}

int main() {
    string s;
    cin >> s;
    cout << countDistinctSubstring(s) - 1 << endl;
    return 0;
}
