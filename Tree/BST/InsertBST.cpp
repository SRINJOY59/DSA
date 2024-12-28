#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int data)
{

    if (root == NULL)
    {
        return new Node(data);
    }
    Node *curr = root;
    while (true)
    {

        if (curr->data == data)
        {
            break;
        }
        if (curr->data < data)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(data);
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(data);
                break;
            }
        }
    }
    return root;
}