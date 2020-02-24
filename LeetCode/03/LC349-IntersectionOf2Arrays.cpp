// LC349-IntersectionOf2Array.cpp
// Ad
// Init: 19Sep24

// Difficulty: Easy
// Status: Accepted
// Time: 21' + 9'
// Runtime: 99%
// Memory: 46%

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        if (nums1.empty() || nums2.empty())
            return ret;

        unordered_set<int> set1;
        for (auto i : nums1)
            set1.insert(i);

        unordered_set<int> inserted;
        for (auto i : nums2)
            if (set1.find(i) != set1.end() && inserted.find(i) == inserted.end())
            {
                ret.push_back(i);
                inserted.insert(i);
            }

        return ret;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums1{4, 9, 5}, nums2{9, 4, 9, 8, 4};

    for (auto i : sol.intersection(nums1, nums2))
        cout << i << endl;

    system("pause");
    return 0;
}
