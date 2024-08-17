#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node()
        : val(0), left(nullptr), right(nullptr) {}
    Node(int x)
        : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right)
        : val(x), left(left), right(right) {}
};

int countNodes(Node *root)
{
    // Write your code here
    if (root == NULL)
    {
        return 0;
    }
    int lh = heightLeft(root);
    int rh = heightRight(root);

    if (lh == rh)
    {
        return (1 << lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int heightLeft(Node *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}
int heightRight(Node *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}