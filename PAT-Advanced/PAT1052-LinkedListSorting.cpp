// PAT1052-LinkedListSorting.cpp
// Ad
// Init: 19Aug21

// Score: 25/25
// Time: 49'
// Runtime: 307 ms

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node;
vector<Node> sortLinkedList(const map<int, Node> &nodes, int head);

// Class -----------------------------------------------------------------------

struct Node
{
    int addr;
    int key;
    int next;

    Node(int a, int k, int n) : addr{a}, key{k}, next{n} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    int len = 0, head = 0;
    cin >> len >> head;
    map<int, Node> nodes;
    for (int i = 0; i < len; ++i)
    {
        int addr = 0, key = 0, next = 0;
        cin >> addr >> key >> next;
        nodes.insert({addr, {addr, key, next}});
    }

    vector<Node> linkedList = sortLinkedList(nodes, head);

    cout << linkedList.size();
    for (auto node : linkedList)
        printf(" %.5d\n%.5d %d", node.addr, node.addr, node.key);
    cout << ' ' << -1 << endl;

    // system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<Node> sortLinkedList(const map<int, Node> &nodes, int head)
{
    vector<Node> linkedList;
    if (head == -1)
        return linkedList;

    linkedList.push_back(nodes.at(head));
    while (linkedList.back().next != -1)
        linkedList.push_back(nodes.at(linkedList.back().next));

    sort(linkedList.begin(), linkedList.end(), [](const Node &node1, const Node &node2) { return node1.key <= node2.key; });

    return linkedList;
}
