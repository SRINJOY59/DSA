#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void dfs(BinaryTreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    int parentSum = root->data;
    int total = 0;
    if(root->left){
        total += root->left->data;
    }
    if(root->right){
        total += root->right->data;
    }
    if(total >= parentSum){
        root->data = total;
    }
    else{
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    dfs(root->left);
    dfs(root->right);
    int sum = 0;
    if(root->left){
        sum += root->left->data;
    }
    if(root->right){
        sum += root->right->data;
    }
    if(sum > 0){
        root->data = sum;
    }
}

void changeTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return ;
    }
    dfs(root);
}
