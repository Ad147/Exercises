// PAT1030-TravelPlan.cpp
// Ad
// Init: 19May22

// Score: (unfinished)
// Spent time: 60 min
// Runtime: (unfinished)

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct City;
vector<City> inputCitiesAndWays(int numCities, int numWays);
City *calculation(vector<City> cities, int start, int dest);
void printPath(City *dest);

// Class -----------------------------------------------------------------------

struct City
{
    int id;
    vector<City *> adj;
    City *path;
    int dist;
    int cost;
    bool known;

    City() : id{65536}, adj{}, path{nullptr}, dist{65536}, cost{65536}, known{false} {}

    bool operator<(const City &rhs) { return (dist == rhs.dist ? cost < rhs.cost : dist < rhs.dist); }
};

// Main ------------------------------------------------------------------------

int main()
{
    int numCities = 0, numWays = 0, start = 65536, dest = 65536;
    cin >> numCities >> numWays >> start >> dest;

    vector<City> cities = inputCitiesAndWays(numCities, numWays);
    City *res = calculation(cities, start, dest);
    printPath(res);
    cout << ' ' << res->dist << ' ' << res->cost << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<City> inputCitiesAndWays(int numCities, int numWays)
{
    vector<City> cities(numCities);
    for (int i = 0; i < cities.size(); ++i)
        cities[i].id = i;

    for (int i = 0; i < numWays; ++i)
    {
        int c1 = 65536, c2 = 65536, dist = 0, cost = 0;
        cin >> c1 >> c2 >> dist >> cost;
        cities[c1].adj.push_back(&cities[c2]);
        cities[c2].adj.push_back(&cities[c1]);
        // TODO: store dist and cost.
    }

    return cities;
}

City *calculation(vector<City> cities, int start, int dest)
{
    return &cities.back(); // Test
}

void printResult(City *res)
{
    if (res->path)
        printPath(res->path);
    else
        cout << res->id;
}
