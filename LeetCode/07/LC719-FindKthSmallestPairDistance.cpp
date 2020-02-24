// LC719-FindKthSmallestPairDistance.cpp
// Ad
// Init: 19Sep28

// Difficulty: Hard
// Status: Time Limit Exceeded
// Time: 25'
// Runtime: -
// Memory: -

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Solution ====================================================================

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        multiset<int> dists;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                dists.insert(abs(nums[i] - nums[j]));

        auto itr = dists.cbegin();
        for (int i = 1; i < k; ++i)
            ++itr;

        return *itr;
    }
};

// Main ========================================================================

int main()
{
    Solution sol;
    vector<int> nums{1, 3, 1};
    int k = 1;

    cout << sol.smallestDistancePair(nums, k) << endl;

    system("pause");
    return 0;
}
