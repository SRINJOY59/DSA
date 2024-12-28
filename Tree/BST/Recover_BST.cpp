                                
#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Store first node of the misplaced pair
    TreeNode* first;    
    // Store previous node during inorder traversal
    TreeNode* prev;     
    // Store second node of the misplaced pair
    TreeNode* middle; 
    // Store last node of the misplaced pair
    TreeNode* last;     

private:
    // Helper function to perform inorder
    // traversal and find misplaced nodes
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // Traverse left subtree
        inorder(root->left);  
        
        // Check for misplaced nodes
        if (prev != NULL && root->val < prev->val) {
            // If this is the first violation,
            // mark nodes as 'first' and 'middle'
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                // If it's not the first
                // violation, mark 'last'
                last = root;  
            }
        }
        
        // Update 'prev' for the
        // next iteration
        prev = root;
        // Traverse right subtree
        inorder(root->right);  
    }

public:
    // Function to recover the binary search tree
    void recoverTree(TreeNode* root) {
        // Initialize node pointers
        first = middle = last = NULL;      
        // Initialize prev with a minimum value
        prev = new TreeNode(INT_MIN);      
        // Perform inorder traversal
        inorder(root);                     
        
        // Swap the values of misplaced
        // nodes based on conditions
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};

// Utility function to
// insert nodes into the BST
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

// Function to swap two tree
// nodes and their subtrees
void swapNodes(TreeNode* a, TreeNode* b) {
    // Swap values of the nodes
    int temp = a->val;
    a->val = b->val;
    b->val = temp;

    // Swap left subtrees of the nodes
    TreeNode* tempLeft = a->left;
    a->left = b->left;
    b->left = tempLeft;

    // Swap right subtrees of the nodes
    TreeNode* tempRight = a->right;
    a->right = b->right;
    b->right = tempRight;
}

int main() {
    Solution solution;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 3);
    insert(root, 1);
    insert(root, 4);
    insert(root, 2);

    cout << "Original BST: ";
    inorderTraversal(root);
    cout << endl;


    // Intentionally swapping two nodes (4 and 2) 
    TreeNode* node4 = root->right;
    TreeNode* node2 = root->left->right;
    swapNodes(node4, node2);
    
    cout << "BST with swapped nodes: ";
    inorderTraversal(root);
    cout << endl;
    
    // Recover the BST
    solution.recoverTree(root);
    
    cout << "Recovered BST: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
                                
                            