// PAT1056-MiceAndRice.cpp
// Ad
// Init: 19Aug25

// Score: 25/25
// Time: 55'
// Runtime: 5 ms

#include <iostream>
#include <vector>

using namespace std;

void playRound(const vector<int> &weights, const vector<int> &order, int groupCapa, vector<int> &rank);

// Main ------------------------------------------------------------------------

int main()
{
    int numPlayers = 0, groupCapa = 0;
    cin >> numPlayers >> groupCapa;
    vector<int> weights(numPlayers);
    for (int i = 0; i < numPlayers; ++i)
    {
        int weight = 0;
        cin >> weight;
        weights[i] = weight;
    }
    vector<int> order(numPlayers);
    for (int i = 0; i < numPlayers; ++i)
    {
        int n = 0;
        cin >> n;
        order[i] = n;
    }

    vector<int> rank(numPlayers);
    playRound(weights, order, groupCapa, /*out*/ rank);

    if (!rank.empty())
        cout << rank.front();
    for (int i = 1; i < numPlayers; ++i)
        cout << ' ' << rank[i];
    cout << endl;

    system("pause");
    return 0;
}

// Function --------------------------------------------------------------------

void playRound(const vector<int> &weights, const vector<int> &order, int groupCapa, vector<int> &rank)
{
    if (order.size() == 1)
    {
        rank[order.front()] = 1;
        return;
    }

    vector<int> newOrder;
    for (int i = 0; i < order.size(); i += groupCapa)
    {
        int max = 0;
        for (int j = 0; j < groupCapa; ++j)
        {
            if (i + j >= order.size())
                break;

            if (weights[order[i + j]] > max)
                max = weights[order[i + j]];
        }

        for (int j = 0; j < groupCapa; ++j)
        {
            if (i + j >= order.size())
                break;

            if (weights[order[i + j]] == max)
                newOrder.push_back(order[i + j]);
        }
    }

    int currRank = newOrder.size() + 1;
    for (auto i : order)
        rank[i] = currRank;

    playRound(weights, newOrder, groupCapa, rank);
}
