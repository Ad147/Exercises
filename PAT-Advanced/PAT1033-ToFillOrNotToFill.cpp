// PAT1033-ToFillOrNotToFill.cpp
// Ad
// Init: 19May27

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<float, int>> inputStations(int numStations);
void getResult(vector<pair<float, int>> stations, int tankCapa, int dist, int distPerGas);

// Main ------------------------------------------------------------------------

int main()
{
    int tankCapa = 0, dist = 0, distPerGas = 0, numStations = 0;
    cin >> tankCapa >> dist >> distPerGas >> numStations;

    vector<pair<float, int>> stations = inputStations(numStations);

    getResult(stations, tankCapa, dist, distPerGas);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<pair<float, int>> inputStations(int numStations)
{
    vector<pair<float, int>> ret;
    float price = 0.;
    int dist = 0;

    for (int i = 0; i < numStations; ++i)
    {
        cin >> price >> dist;
        ret.push_back({price, dist});
    }
    sort(ret.begin(), ret.end(), [](pair<float, int> lhs, pair<float, int> rhs) { return lhs.second < rhs.second; });

    return ret;
}

void getResult(vector<pair<float, int>> stations, int tankCapa, int dist, int distPerGas)
{
    float total = 0.;
}
