// PAT1021-DeepestRoot.cpp
// Ad
// Init: 19Apr11

// Score: 23/25.
// Runtime: 965 ms.
// Spent time: 145 min.

/* -----------------------------------------------------------------------------

1021 Deepest Root （25 分)

A graph which is connected and acyclic can be considered a tree. 
The height of the tree depends on the selected root. 
Now you are supposed to find the root that results in a highest tree. 
Such a root is called the deepest root.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains a positive integer N (≤10^4) which is the number of nodes, and hence the nodes are numbered from 1 to N. 
Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

### Output Specification:

For each test case, print each of the deepest roots in a line. 
If such a root is not unique, print them in increasing order of their numbers. 
In case that the given graph is not a tree, print `Error: K components` where `K` is the number of connected components in the graph.

----------------------------------------
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
----------------------------------------
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// Class -----------------------------------------------------------------------

class Graph
{
  private:
    struct Node
    {
        int id;
        vector<Node *> adj;
        bool known;
        int dist;
        Node *last;

        Node() = default;
        Node(int i) : id{i}, known{false}, dist{-1}, last{nullptr} {}
    };

    vector<Node> nodes;
    map<int, set<Node *>> roots;
    int numComponents;

  public:
    Graph(void) = default;
    Graph(int n);

    void inputEdges(void);

    void printDeepestRoots(void);
    int getNumComponents(void) { return numComponents; }

    void calcDeepestRoots(void);

  private:
    void initNodes(void);
    Node *findMaxLength(void);
};

// Main ------------------------------------------------------------------------

int main()
{
    int numNodes = 0;
    cin >> numNodes;

    Graph g{numNodes};
    g.inputEdges();

    g.calcDeepestRoots();

    if (g.getNumComponents() == 1)
        g.printDeepestRoots();
    else
        cout << "Error: " << g.getNumComponents() << " components" << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

Graph::Graph(int n) : numComponents{0}
{
    for (int i = 1; i < n + 1; ++i)
        nodes.push_back(Node{i});
}

void Graph::inputEdges(void)
{
    for (int i = 0; i < nodes.size() - 1; ++i)
    {
        int n1 = 0, n2 = 0;
        cin >> n1 >> n2;
        nodes[n1 - 1].adj.push_back(&nodes[n2 - 1]);
        nodes[n2 - 1].adj.push_back(&nodes[n1 - 1]);
    }
}

void Graph::printDeepestRoots(void)
{
    for (auto r : roots.rbegin()->second)
        cout << r->id << endl;
}

void Graph::calcDeepestRoots(void)
{
    for (auto &root : nodes)
    {
        int maxDepth = 0;
        initNodes();
        root.dist = 0;

        while (true)
        {
            auto curr = findMaxLength();
            if (!curr)
                break;

            if (maxDepth < curr->dist)
                maxDepth = curr->dist;
            curr->known = true;

            for (auto p : curr->adj)
                if (p->dist < curr->dist + 1)
                {
                    p->dist = curr->dist + 1;
                    p->last = curr;
                }
        }

        roots[maxDepth].insert(&root);
    }

    numComponents = numComponents / nodes.size() + 1;
}

void Graph::initNodes(void)
{
    for (auto &n : nodes)
    {
        n.known = false;
        n.dist = -1;
        n.last = nullptr;
    }
}

Graph::Node *Graph::findMaxLength(void)
{
    int maxLength = -1;
    Node *maxLengthNode = nullptr;
    for (auto &n : nodes)
        if (!n.known && maxLength < n.dist)
        {
            maxLength = n.dist;
            maxLengthNode = &n;
        }

    if (maxLengthNode)
        return maxLengthNode;

    for (auto &n : nodes)
        if (!n.known)
        {
            maxLengthNode = &n;
            break;
        }

    if (maxLengthNode)
        ++numComponents;

    return maxLengthNode;
}
