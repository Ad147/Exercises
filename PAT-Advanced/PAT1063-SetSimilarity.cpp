// PAT1063-SetSimilarity.cpp
// Ad
// Init: 19Sep01

// Score: OSK/25
// Time: 33'
// Runtime: 180 ms

#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

float calcSetSimilarity(const pair<int, int> &query, const vector<set<int>> &sets);

// Main ------------------------------------------------------------------------

int main()
{
	int numSets = 0;
	cin >> numSets;
	vector<set<int>> sets(numSets);
	for (int i = 0; i < numSets; ++i)
	{
		int numInts = 0;
		cin >> numInts;
		for (int j = 0; j < numInts; ++j)
		{
			int n = 0;
			cin >> n;
			sets[i].insert(n);
		}		
	}
	
	int numQueries = 0;
	cin >> numQueries;
	vector<pair<int, int>> queries;
	for (int i = 0; i < numQueries; ++i)
	{
		int set1 = 0, set2 = 0;
		cin >> set1 >> set2;
		queries.push_back({set1, set2});
	}
	
	for (auto query : queries)
		printf("%.1f\%\n", calcSetSimilarity(query, sets) * 100);
	
	return 0;
}

// Functions -------------------------------------------------------------------

float calcSetSimilarity(const pair<int, int> &query, const vector<set<int>> &sets)
{
	const set<int> &set1 = sets[query.first - 1], &set2 = sets[query.second - 1];
	float common = 0.0f;
	for (auto i : set1)
		if (set2.find(i) != set2.cend())
			++common;
	
	return common / (set1.size() + set2.size() - common);
}

