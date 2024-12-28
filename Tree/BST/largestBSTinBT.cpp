                                
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    // Constructor to initialize
    // the NodeValue object
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    // Helper function to find the
    // largest BST subtree recursively
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right
        // subtrees of the current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Check if the current tree is a BST based
        // on its left and right subtrees' properties
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST, update the values for the current tree
            return NodeValue(min(root->val, left.minNode),
                max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // If the current tree is not a BST,
        // return values indicating invalid tree properties
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Function to find the size
    // of the largest BST subtree
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

// Utility function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Utility function to perform
// inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {
    Solution solution;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    
    // Create a new tree, attaching the
    // BST root as the left child of a new root
    TreeNode* newRoot = new TreeNode(6);
    newRoot->left = root;
    newRoot->right = new TreeNode(3);

    // Display the original tree using inorder traversal
    cout << "Original BST: ";
    inorderTraversal(newRoot);
    cout << endl;

    // Find the size of the largest BST subtree
    int largestBSTSize = solution.largestBSTSubtree(newRoot);
    
    // Display the size of the largest BST subtree found
    cout << "Size of the largest BST subtree: " << largestBSTSize << endl;

    return 0;
}
                    



