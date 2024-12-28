#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *search(Node *root, int x)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    if (x > root->data)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }
}

Node *getNode(Node *root)
{
    if (!root->left)
    {
        return root;
    }
    return getNode(root->left);
}

Node *inOrderSuccessor(Node *root, Node *x)
{
    int key = x->data;
    Node *keyNode = search(root, key);

    if (!keyNode)
    {
        return NULL;
    }

    if (keyNode->right)
    {
        return getNode(keyNode->right);
    }

    Node *successor = NULL;
    Node *ancestor = root;

    while (ancestor != keyNode)
    {
        if (keyNode->data < ancestor->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }

    return successor;
}

//O(H)

Node* inOrderSuccessor(Node* root, Node* x) {


    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != NULL) {
        if (x->data < ancestor->data) {
            successor = ancestor;  
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}