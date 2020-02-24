// LC350-IntersectionOf2Arrays2.cpp
// Ad
// Init: 19Sep25

// Difficulty: Easy
// Status: OSK
// Time: 14'
// Runtime: 99%
// Memory: 8%

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        if (nums1.empty() || nums2.empty())
            return ret;

        unordered_map<int, size_t> map1;
        for (auto i : nums1)
            map1[i]++;

        for (auto i : nums2)
            if (map1[i] != 0)
            {
                ret.push_back(i);
                map1[i]--;
            }

        return ret;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums1{4, 9, 5}, nums2{9, 4, 9, 8, 4};

    for (auto i : sol.intersect(nums1, nums2))
        cout << i << endl;

    system("pause");
    return 0;
}
