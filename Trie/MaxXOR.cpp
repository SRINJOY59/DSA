#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];
    
    Node() {
        links[0] = links[1] = NULL;
    }
    
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int maxXOR(int num) {
        int maxi = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxi = maxi | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    Trie trie;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        trie.insert(arr[i]);
    }
    vector<int> brr(m);
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }
    int maxi = 0;
    for (int i = 0; i < m; i++) {
        int val = trie.maxXOR(brr[i]);
        maxi = max(maxi, val);
    }
    cout << maxi << endl;
    return 0;
}
