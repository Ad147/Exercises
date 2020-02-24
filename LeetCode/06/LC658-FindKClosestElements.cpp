// LC658-FindKClosestElements.cpp
// Ad
// Init: 19Sep17

// Difficulty: Medium
// Status: Accepted
// Time: 50'
// Runtime: 98%
// Memory: 16%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ret;
        if (arr.empty())
            return ret;

        int closestIdx = -1;
        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                closestIdx = mid;
                break;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        closestIdx = left;

        int i = closestIdx - 1, j = closestIdx + 1;
        for (int n = 0; n < k - 1; ++n)
        {
            if (i < 0)
                ++j;
            else if (j >= arr.size())
                --i;
            else
            {
                int diff1 = abs(x - arr[i]);
                int diff2 = abs(arr[j] - x);
                if (diff1 > diff2)
                    ++j;
                else
                    --i;
            }
        }

        for (int idx = i + 1; idx <= j - 1; ++idx)
            ret.push_back(arr[idx]);

        return ret;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> arr{0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    int k = 3, x = 5;

    auto res = sol.findClosestElements(arr, k, x);
    for (auto e : res)
        cout << e << endl;

    system("pause");
    return 0;
}