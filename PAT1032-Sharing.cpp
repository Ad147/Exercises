// PAT1032-Sharing.cpp
// Ad
// Init: 19May24

// Score: 23/25
// Spent time: 28 min
// Runtime: 185 ms

/* -----------------------------------------------------------------------------

1032 Sharing (25 分)

To store English words, one method is to use linked lists and store a word letter by letter. 
To save some space, we may let the words share the same sublist if they share the same suffix. 
For example, loading and being are stored as showed in Figure 1.

###### Figure 1
----------------------------------------
word1 --> l --> o --> a --> d --+
                                |--> i --> n --> g --> NULL
word2 --> b --> e --------------+
----------------------------------------

You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).

### Input Specification:

Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (≤10^5), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. 
The address of a node is a 5-digit positive integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:
----------------------------------------
Address Data Next
----------------------------------------

where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from { a-z, A-Z }, and Next is the position of the next node.

### Output Specification:

For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output -1 instead.

----------------------------------------
Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
----------------------------------------
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node;
unordered_map<int, Node> inputMemory(int numNodes);
int findShare(const unordered_map<int, Node> &memory, int head1, int head2);

// Class -----------------------------------------------------------------------

struct Node
{
    char val;
    int next;

    Node(char v, int n) : val{v}, next{n} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    int head1 = 0, head2 = 0, numNodes = 0;
    cin >> head1 >> head2 >> numNodes;

    auto memory = inputMemory(numNodes);

    auto share = findShare(memory, head1, head2);

    cout << share << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

unordered_map<int, Node> inputMemory(int numNodes)
{
    unordered_map<int, Node> memory;
    char c = 0;
    int addr = 0, next = 0;

    for (int i = 0; i < numNodes; ++i)
    {
        cin >> addr >> c >> next;
        memory.insert({addr, {c, next}});
    }

    return memory;
}

int findShare(const unordered_map<int, Node> &memory, int head1, int head2)
{
    unordered_set<int> word1;
    while (head1 != -1)
    {
        word1.insert(head1);
        head1 = memory.at(head1).next;
    }

    while (head2 != -1)
        if (word1.find(head2) != word1.end())
            return head2;
        else
            head2 = memory.at(head2).next;

    return -1;
}
