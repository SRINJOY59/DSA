#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int input)
{
    // Code here
    if (root == NULL)
        return -1;

    // Your code here
    int floorVal = -1;
    while (root != NULL)
    {
        if (root->data > input)
        {
            root = root->left;
        }
        else if (root->data == input)
        {
            floorVal = root->data;
            break;
        }
        else
        {
            floorVal = root->data;
            root = root->right;
        }
    }
    return floorVal;
}