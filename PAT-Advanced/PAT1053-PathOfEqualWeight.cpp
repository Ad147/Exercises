// PAT1053-PathOfEqualWeight.cpp
// Ad
// Init: 19Aug22

// Score: OSK/30
// Time: 54'
// Runtime: 3 ms

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node;
vector<vector<int>> calculateEqualWeightPaths(const vector<Node> &nodes, int target);

// Class -----------------------------------------------------------------------

struct Node
{
    int id;
    int wei;
    vector<int> children;
    int parent;
};

// Main ------------------------------------------------------------------------

int main()
{
    int numNodes = 0, numNonLeaf = 0, target = 0;
    cin >> numNodes >> numNonLeaf >> target;
    vector<Node> nodes(numNodes);
    for (int i = 0; i < numNodes; ++i)
    {
        int wei = 0;
        cin >> wei;
        nodes[i].wei = wei;
    }
    for (int i = 0; i < numNonLeaf; ++i)
    {
        int id = 0, numChildren = 0;
        cin >> id >> numChildren;
        for (int j = 0; j < numChildren; ++j)
        {
            int child = 0;
            cin >> child;
            nodes[id].children.push_back(child);

            nodes[child].parent = id;
        }
    }
    nodes[0].parent = -1;

    vector<vector<int>> resultPaths = calculateEqualWeightPaths(nodes, target);

    for (auto v : resultPaths)
    {
        if (!v.empty())
            cout << v.front();
        for (int i = 1; i < v.size(); ++i)
            cout << ' ' << v[i];
        cout << endl;
    }

    return 0;
}

// Function --------------------------------------------------------------------

vector<vector<int>> calculateEqualWeightPaths(const vector<Node> &nodes, int target)
{
    vector<vector<int>> ret;
    if (nodes.empty())
        return ret;

    for (auto node : nodes)
    {
        if (!node.children.empty())
            continue;

        int sum = 0, parent = node.parent;
        vector<int> path;

        sum += node.wei;
        path.push_back(node.wei);
        while (parent != -1)
        {
            sum += nodes[parent].wei;
            path.push_back(nodes[parent].wei);
            parent = nodes[parent].parent;
        }

        if (sum == target)
            ret.push_back({path.rbegin(), path.rend()});
    }

    sort(ret.begin(), ret.end(), [](const vector<int> &vec1, const vector<int> &vec2) {
        int minSize = min(vec1.size(), vec2.size());
        for (int i = 0; i < minSize; ++i)
        {
            if (vec1[i] > vec2[i])
                return true;
            else if (vec1[i] < vec2[i])
                return false;
        }
        return vec1.size() > vec2.size(); });

    return ret;
}
