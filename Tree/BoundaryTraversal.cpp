#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

void LeftBoundary(Node* root, vector<int>& arr) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    arr.push_back(root->data);
    if(root->left) {
        LeftBoundary(root->left, arr);
    } else {
        LeftBoundary(root->right, arr); 
    }
}

void LeafNodes(Node* root, vector<int>& arr) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        arr.push_back(root->data);
        return;
    }
    LeafNodes(root->left, arr);
    LeafNodes(root->right, arr);
}

void RightBoundary(Node* root, vector<int>& arr) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if(root->right) {
        RightBoundary(root->right, arr);
    } else {
        RightBoundary(root->left, arr); 
    }
    arr.push_back(root->data); 
}

vector<int> boundary(Node *root) {
    vector<int> arr;
    if(root == NULL) {
        return arr;
    }
    
    if (root->left != NULL || root->right != NULL) {
        arr.push_back(root->data);
    }
    
    LeftBoundary(root->left, arr);
    
    LeafNodes(root, arr);
    
    // arr.pop_back();
    
    RightBoundary(root->right, arr);
    
    return arr;
}