// PAT1018-PublicBikeManagement.cpp
// Ad
// Init: 19Apr08

// Score: 25/30.
// Spent time: 320 min.
// Runtime: 4 ms.

/* -----------------------------------------------------------------------------

1018 Public Bike Management （30 分)

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. 
One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. 
A station is said to be in perfect condition if it is exactly half-full. 
If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. 
And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. 
If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

###### Figure

The above figure illustrates an example. 
The stations are represented by vertices and the roads correspond to the edges. 
The number on an edge is the time taken to reach one end station from another. 
The number written inside a vertex S is the current number of bikes stored at S. 
Given that the maximum capacity of each station is 10. 
To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains 4 numbers: 

- C_max (≤100), always an even number, is the maximum capacity of each station; 
- N (≤500), the total number of stations; 
- Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); 
- M, the number of roads. 

The second line contains N non-negative numbers Ci (i=1,⋯,N) where each C​i is the current number of bikes at Si respectively. 
Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. 
All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print your results in one line. 
First output the number of bikes that PBMC must send. 
Then after one space, output the path in the format: 0−>S1->...->Sp. 
Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. 
The judge's data guarantee that such a path is unique.

----------------------------------------
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Class -----------------------------------------------------------------------

class Graph
{
  private:
    struct Node
    {
        const int numBikes;

        bool marked;
        int distance;
        int lastNode;
        int sentBikes;
        vector<pair<int, int>> adjacency;

        Node() = default;
        Node(int nb) : numBikes{nb}, marked{false}, distance{65536}, lastNode{-1}, sentBikes{65536} {}
    };

    const int perfect;
    const int problemStation;

    vector<Node> nodes;

  public:
    Graph() = default;
    Graph(int c, int ps) : perfect{c / 2}, problemStation{ps} {}

    void inputData(int numNodes, int numEdges);

    int getSentBikes(void);
    int getBackBikes(void);
    void printPath(int node);

    void calcShortestPath(void);

  private:
    int findMinDistNode(void);
    void updateNode(int curr, int last, int cost);
};

// Main ------------------------------------------------------------------------

int main()
{
    int capacity, numStations, problemStation, numRoads;
    cin >> capacity >> numStations >> problemStation >> numRoads;
    Graph g(capacity, problemStation);
    g.inputData(numStations, numRoads);

    g.calcShortestPath();

    cout << g.getSentBikes() << ' ';
    g.printPath(problemStation);
    cout << ' ' << g.getBackBikes() << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

void Graph::inputData(int numNodes, int numEdges)
{
    nodes.push_back(Node{0});
    for (int i = 0; i < numNodes; ++i)
    {
        int numBikes = 0;
        cin >> numBikes;
        nodes.push_back(Node{numBikes});
    }

    for (int i = 0; i < numEdges; ++i)
    {
        int ni = 0, nj = 0, cost = 0;
        cin >> ni >> nj >> cost;
        nodes[ni].adjacency.push_back({nj, cost});
        nodes[nj].adjacency.push_back({ni, cost});
    }
}
// -------------------------------------
int Graph::getSentBikes(void)
{
    int sent = nodes[problemStation].sentBikes;
    return sent < 0 ? 0 : sent;
}
// -------------------------------------
int Graph::getBackBikes(void)
{
    int sent = nodes[problemStation].sentBikes;
    return sent < 0 ? -sent : 0;
}
// -------------------------------------
void Graph::printPath(int node)
{
    if (nodes[node].lastNode < 0)
        cout << node;
    else
    {
        printPath(nodes[node].lastNode);
        cout << "->" << node;
    }
}
// -------------------------------------
void Graph::calcShortestPath(void)
{
    nodes[0].distance = 0;
    nodes[0].sentBikes = 0;

    while (true)
    {
        int minNode = findMinDistNode();
        if (minNode < 0)
            break;

        nodes[minNode].marked = true;

        for (auto n : nodes[minNode].adjacency)
            if (!nodes[n.first].marked)
                updateNode(n.first, minNode, n.second);
    }
}
// -------------------------------------
int Graph::findMinDistNode(void)
{
    int minDist = 65536, minNode = -1;
    for (int i = 0; i < nodes.size(); ++i)
        if (!nodes[i].marked && nodes[i].distance < minDist)
        {
            minDist = nodes[i].distance;
            minNode = i;
        }

    return minNode;
}
// -------------------------------------
void Graph::updateNode(int curr, int last, int cost)
{
    int newDist = nodes[last].distance + cost;
    int newSent = perfect - nodes[curr].numBikes + nodes[last].sentBikes;
    if ((newDist < nodes[curr].distance) ||
        (newDist == nodes[curr].distance && abs(newSent) < nodes[curr].sentBikes))
    {
        nodes[curr].distance = newDist;
        nodes[curr].lastNode = last;
        nodes[curr].sentBikes = newSent;
    }
}
