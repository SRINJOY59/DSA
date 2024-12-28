#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class BSTIterator {
    private:
        stack<TreeNode*>BST_st;
        void pushAll(TreeNode* root){
            while(root != NULL){
                BST_st.push(root);
                root = root->left;
            }
        }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = BST_st.top();
        BST_st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(BST_st.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};