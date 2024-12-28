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

class BSTIterator
{
private:
    stack<Node *> BST_st;
    bool reverse;
    void pushAll(Node *root)
    {
        while (root != NULL)
        {
            BST_st.push(root);
            if (!reverse)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        Node *temp = BST_st.top();
        BST_st.pop();
        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        if (BST_st.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int isPairPresent(struct Node *root, int k)
{
    // add code here.
    if (!root)
    {
        return false;
    }
    BSTIterator b1(root, false);
    BSTIterator b2(root, true);

    int l = b1.next();
    int r = b2.next();

    while (l < r)
    {
        if (l + r == k)
        {
            return true;
        }
        else if (l + r < k)
        {
            l = b1.next();
        }
        else
        {
            r = b2.next();
        }
    }
    return false;
}