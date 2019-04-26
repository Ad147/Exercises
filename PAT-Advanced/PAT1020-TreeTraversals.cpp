// PAT1020-TreeTraversals.cpp
// Ad
// Init: 19Apr10

// Score: 25/25 (One-Shot Kill).
// Spent time: 35 min.
// Runtime: 4 ms.

/* -----------------------------------------------------------------------------

1020 Tree Traversals （25 分)

Suppose that all the keys in a binary tree are distinct positive integers. 
Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. 
The second line gives the postorder sequence and the third line gives the inorder sequence. 
All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. 
All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

----------------------------------------
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using Citr = vector<int>::const_iterator;

struct Node;
vector<int> inputVector(int n);
Node *buildTree(Citr pl, Citr pr, Citr il, Citr ir);
vector<int> levelTraversal(Node *root);

// Class -----------------------------------------------------------------------

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int v) : val{v}, left{nullptr}, right{nullptr} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    int numNodes = 0;
    cin >> numNodes;

    vector<int> post = inputVector(numNodes);
    vector<int> in = inputVector(numNodes);

    Node *root = buildTree(post.cbegin(), post.cend(), in.cbegin(), in.cend());

    vector<int> level = levelTraversal(root);

    cout << level.front();
    for (int i = 1; i < level.size(); ++i)
        cout << ' ' << level[i];
    cout << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<int> inputVector(int n)
{
    vector<int> ret;
    int v = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v;
        ret.push_back(v);
    }

    return ret;
}

Node *buildTree(Citr pl, Citr pr, Citr il, Citr ir)
{
    if (pl >= pr || il >= ir)
        return nullptr;

    int v = *(pr - 1);
    Node *t = new Node{v};

    auto mid = find(il, ir, v);
    t->left = buildTree(pl, pl + (mid - il), il, mid);
    t->right = buildTree(pl + (mid - il), pr - 1, mid + 1, ir);

    return t;
}

vector<int> levelTraversal(Node *root)
{
    vector<int> level;

    deque<Node *> queue{root};
    while (!queue.empty())
    {
        Node *t = queue.front();
        queue.pop_front();
        if (!t)
            continue;

        level.push_back(t->val);

        queue.push_back(t->left);
        queue.push_back(t->right);
    }

    return level;
}
