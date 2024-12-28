#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findCeil(Node* root, int input);

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;
        Node* root = buildTree(s);
        cout << findCeil(root, x) << endl;
    }
    return 1;
}






int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceilVal = -1;
    while(root != NULL){
        if(root->data > input){
            ceilVal = root->data;
            root = root->left;
        }
        else if(root->data == input){
            ceilVal = root->data;
            break;
        }
        else{
            root = root->right;
        }
    }
    return ceilVal;
}