#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *build(vector<int> &A, int &i, int bound)
{
    if (i == A.size() || A[i] > bound)
    {
        return NULL;
    }
    Node *root = newNode(A[i++]);
    root->left = build(A, i, root->data);
    root->right = build(A, i, bound);
    return root;
}
Node *Bst(int pre[], int size)
{
    // code here
    int i = 0;

    vector<int> A(pre, pre + size);
    return build(A, i, INT_MAX);
}