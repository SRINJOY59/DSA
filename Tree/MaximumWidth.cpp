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

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    queue<pair<TreeNode*, unsigned long long>> q; 
    q.push({root, 0});
    int ans = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        unsigned long long min = q.front().second; // The minimum index at the current level
        unsigned long long first = 0, last = 0;
        
        for (int i = 0; i < sz; i++) {
            unsigned long long cur_id = q.front().second - min; // Normalize the index
            TreeNode* node = q.front().first;
            q.pop();
            
            if (i == 0) first = cur_id;
            if (i == sz - 1) last = cur_id;
            
            if (node->left != NULL) {
                q.push({node->left, cur_id * 2 + 1});
            }
            if (node->right != NULL) {
                q.push({node->right, cur_id * 2 + 2});
            }
        }
        
        ans = max(ans, static_cast<int>(last - first + 1));
    }
    
    return ans;
}
