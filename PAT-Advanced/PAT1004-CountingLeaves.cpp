// PAT1004-CountingLeaves.cpp
// Ad
// Init: 19Mar27

// Score: 30/30.
// Spent time: 135 min.
// Runtime: 3 ms.

/* -----------------------------------------------------------------------------

1004 Counting Leaves （30 分)

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

### Input Specification:

Each input file contains one test case. 
Each case starts with a line containing 0<N<100, the number of nodes in a tree, and M (<N), the number of non-leaf nodes. 
Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. 
For the sake of simplicity, let us fix the root ID to be 01.

The input ends with N being 0. 
That case must NOT be processed.

### Output Specification:

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. 
The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. 
Hence on the root 01 level, there is 0 leaf node; 
and on the next level, there is 1 leaf node. 
Then we should output 0 1 in a line.

----------------------------------------
Sample Input:
2 1
01 1 02
Sample Output:
0 1
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

struct Node;
Node *build(vector<Node *> nodes, int M);
void count(Node *t, vector<int> *noChildNum, int idx);

// Classes ---------------------------------------------------------------------

struct Node
{
    int id;
    Node *child;
    Node *next;

    Node(int i) : id{i}, child{nullptr}, next{nullptr} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    int N, M;
    cin >> N >> M;
    vector<Node *> nodes(100);
    Node *root = build(nodes, M);

    vector<int> noChildNum;
    count(root, &noChildNum, 0);

    cout << noChildNum[0];
    for (int i = 1; i < noChildNum.size(); ++i)
        cout << ' ' << noChildNum[i];
    cout << endl;

    // system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

Node *build(vector<Node *> nodes, int M)
{
    Node *root = new Node{1};
    nodes[1] = root;

    for (int i = 0; i < M; ++i)
    {
        int parentId, K, firstChildId;
        cin >> parentId >> K >> firstChildId;

        if (!nodes[parentId])
            nodes[parentId] = new Node(parentId);
        if (!nodes[firstChildId])
            nodes[firstChildId] = new Node(firstChildId);

        nodes[parentId]->child = nodes[firstChildId];

        Node *t = nodes[firstChildId];
        for (int j = 1; j < K; ++j)
        {
            int id;
            cin >> id;
            t->next = new Node(id);
            t = t->next;
            nodes[id] = t;
        }
    }

    return root;
}

void count(Node *t, vector<int> *noChildNum, int idx)
{
    if (!t)
        return;

    if (idx >= noChildNum->size())
        noChildNum->push_back(0);

    if (!t->child)
        ++(*noChildNum)[idx];

    count(t->next, noChildNum, idx);
    count(t->child, noChildNum, idx + 1);
}
