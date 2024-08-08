#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> preOrder(Node *root)
{
    // code here
    if (root == NULL)
    {
        return {};
    }
    stack<Node *> st;
    st.push(root);
    vector<int> preorder;
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        preorder.push_back(node->data);
        if (node->right != NULL)
        {
            st.push(node->right);
        }
        if (node->left != NULL)
        {
            st.push(node->left);
        }
    }
    return preorder;
}