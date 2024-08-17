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


void solve(TreeNode* target, int k, int count, vector<int>& arr) {
    if (target == NULL) {
        return;
    }
    if (count == k) {
        arr.push_back(target->val);
        return;
    }
    solve(target->left, k, count + 1, arr);
    solve(target->right, k, count + 1, arr);
}

int dist(TreeNode* root, TreeNode* target, vector<int>& ans, int k) {
    if (root == NULL) {
        return -1;
    }
    if (root->val == target->val) {
        solve(root, k, 0, ans);
        return 0;
    }

    int leftDist = dist(root->left, target, ans, k);
    if (leftDist != -1) {
        if (leftDist + 1 == k) {
            ans.push_back(root->val);
        } else {
            solve(root->right, k - leftDist - 2, 0, ans);
        }
        return leftDist + 1;
    }

    int rightDist = dist(root->right, target, ans, k);
    if (rightDist != -1) {
        if (rightDist + 1 == k) {
            ans.push_back(root->val);
        } else {
            solve(root->left, k - rightDist - 2, 0, ans);
        }
        return rightDist + 1;
    }

    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    dist(root, target, ans, k);
    return ans;
}
