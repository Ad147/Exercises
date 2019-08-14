// PAT1046-ShortestDistance.cpp
// Ad
// Init: 19Aug14

// Score: 17/20
// Time: 50'
// Runtime: 3 ms

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int shortestDist(const pair<int, int> &q, const vector<int> &dists, int total);

// Main ------------------------------------------------------------------------

int main()
{
    int numDist = 0;
    cin >> numDist;
    vector<int> dists;
    for (int i = 0; i < numDist; ++i)
    {
        int d = 0;
        cin >> d;
        dists.push_back(d);
    }

    int numQueries = 0;
    cin >> numQueries;
    vector<pair<int, int>> queries;
    for (int i = 0; i < numQueries; ++i)
    {
        int first = 0, second = 0;
        cin >> first >> second;
        queries.push_back({first, second});
    }

    int total = 0;
    for (auto d : dists)
        total += d;

    for (auto q : queries)
        cout << shortestDist(q, dists, total) << endl;

    return 0;
}

// Function --------------------------------------------------------------------

int shortestDist(const pair<int, int> &q, const vector<int> &dists, int total)
{
    if (dists.empty())
        return 0;

    int sum = 0, beg = min(q.first, q.second), end = max(q.first, q.second), diff = q.second - q.second;
    if (diff != min(diff, (int)(dists.size() - diff)))
        swap(beg, end);

    for (int i = beg - 1; i < end - 1; ++i)
    {
        sum += dists[i];
        if (i == dists.size() - 1)
            i = 0;
    }

    return min(sum, total - sum);
}
