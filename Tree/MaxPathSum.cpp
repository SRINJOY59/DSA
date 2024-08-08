#include<bits/stdc++.h>
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


int heightCumSum(TreeNode* root, int &maxPath){
    if(root == NULL){
        return 0;
    }
    int left = max(0, heightCumSum(root->left, maxPath));  //don't include negative path
    int right = max(0, heightCumSum(root->right, maxPath));
    maxPath = max(maxPath, root->val + left + right);
    return root->val + max(left, right);
}
    int maxPathSum(TreeNode* root) {
        // int ans = 0;
        if(root == NULL){
            return 0;
        }
        int ans = INT_MIN;
        int h = heightCumSum(root, ans);
        return ans;
    }