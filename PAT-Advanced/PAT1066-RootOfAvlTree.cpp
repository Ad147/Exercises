// PAT1066-RootOfAvlTree.cpp
// Ad
// Init: 19Sep04

// Score: 21/25
// Time: 60'
// Runtime: 8 ms

// P.S. this solution ignores height refresh after rotation, need modify.

#include <iostream>
#include <vector>

using namespace std;

struct Node;
Node *buildTree(const vector<int> &keys);
Node *buildTree(int key, Node *root);
int height(Node *node);
Node *rotateRight(Node *root);
Node *rotateLeft(Node *root);

// Class -------------------------------------------------------------

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Main --------------------------------------------------------------

int main()
{
    int numNodes = 0;
    cin >> numNodes;
    vector<int> keys;
    for (int i = 0; i < numNodes; ++i)
    {
        int n = 0;
        cin >> n;
        keys.push_back(n);
    }

    Node *root = buildTree(keys);

    if (root)
        cout << root->key << endl;
    
    return 0;
}

// Functions ---------------------------------------------------------

Node *buildTree(const vector<int> &keys)
{
    if (keys.empty())
        return nullptr;
    Node *root = new Node{keys.front(), nullptr, nullptr, 1};

    for (int i = 1; i < keys.size(); ++i)
        root = buildTree(keys[i], root);

    return root;
}

Node *buildTree(int key, Node *root)
{
    if (key < root->key)
        if (root->left)
            root->left = buildTree(key, root->left);
        else
            root->left = new Node{key, nullptr, nullptr, 1};
    else
        if (root->right)
            root->right = buildTree(key, root->right);
        else
            root->right = new Node{key, nullptr, nullptr, 1};
    
    if (height(root->left) - height(root->right) > 1)
        root = rotateRight(root);
    else if (height(root->right) - height(root->left) > 1)
        root = rotateLeft(root);

    root->height = max(height(root->left), height(root->right)) + 1;

    return root;
}

int height(Node *node)
{
    if (node)
        return node->height;
    else
        return 0;
}

Node *rotateRight(Node *root)
{
    if (height(root->left->left) > height(root->left->right))
    {
        Node *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
    else
    {
        Node *newRoot = root->left->right;
        root->left->right = newRoot->left;
        newRoot->left = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
}

Node *rotateLeft(Node *root)
{
    if (height(root->right->right) > height(root->right->left))
    {
        Node *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }
    else
    {
        Node *newRoot = root->right->left;
        root->right->left = newRoot->right;
        newRoot->right = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }
}
