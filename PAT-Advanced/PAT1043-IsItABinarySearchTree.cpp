// PAT1043-IsItABinarySearchTree.cpp
// Ad
// Init: 19Aug11

// Score: 11/25
// Time: 60 min
// Runtime: 4ms

#include <iostream>
#include <vector>

using namespace std;

struct Node;
Node *buildTree(vector<int>::const_iterator beg, vector<int>::const_iterator end);
void postorderTraversal(const Node *root, vector<int> &postorder);
void inorderTraversal(const Node *root, vector<int> &inorder);
bool isBST(const Node *root);

// Class -----------------------------------------------------------------------

struct Node
{
    int val;
    Node *left;
    Node *right;
};

// Main ------------------------------------------------------------------------

int main()
{
    int numNodes = 0;
    cin >> numNodes;
    vector<int> preorder;
    for (int i = 0; i < numNodes; ++i)
    {
        int val = 0;
        cin >> val;
        preorder.push_back(val);
    }

    Node *root = buildTree(preorder.cbegin(), preorder.cend());
    vector<int> postorder;
    postorderTraversal(root, postorder);
    if (isBST(root))
    {
        cout << "YES" << endl
             << postorder[0];
        for (int i = 1; i < postorder.size(); ++i)
            cout << ' ' << postorder[i];
        cout << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}

// Functions -------------------------------------------------------------------

Node *buildTree(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg == end)
        return nullptr;

    Node *root = new Node{};
    root->val = *beg;
    root->left = buildTree(beg + 1, beg + (end - beg) / 2 + 1);
    root->right = buildTree(beg + (end - beg) / 2 + 1, end);

    return root;
}

void postorderTraversal(const Node *root, vector<int> &postorder)
{
    if (!root)
        return;

    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->val);
}

void inorderTraversal(const Node *root, vector<int> &inorder)
{
    if (!root)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

bool isBST(const Node *root)
{
    if (!root)
        return false;

    vector<int> inorder;
    inorderTraversal(root, inorder);
    for (int i = 0, j = 1; j < inorder.size(); ++i, ++j)
        if (inorder[i] > inorder[j])
            return false;

    return true;
}
