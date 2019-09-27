// LC004-MedianOf2SortedArrays.cpp
// Ad
// Init: 19Sep27

// Difficulty: Hard
// Status: Runtime Error
// Time: 46
// Runtime: -
// Memory: -

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
    {
        if (nums1.empty())
            return findMedian(nums2);
        else if (nums2.empty())
            return findMedian(nums1);

        size_t left1 = 0, right1 = nums1.size() - 1, left2 = 0, right2 = nums2.size() - 1;
        size_t mid1 = left1 + (right1 - left1) / 2, mid2 = left2 + (right2 - left2) / 2;
        while (left1 < right1 && left2 < right2)
        {
            if (nums1[mid1] == nums2[mid2])
                return nums1[mid1];
            else if (nums1[mid1] < nums2[mid2])
                right2 = mid2;
            else
                left2 = mid2 + 1;

            mid2 = left2 + (right2 - left2) / 2;
            if (nums1[mid1] == nums2[mid2])
                return nums1[mid1];
            else if (nums1[mid1] < nums2[mid2])
                left1 = mid1 + 1;
            else
                right1 = mid1;
        }

        mid1 = left1 + (right1 - left1) / 2, mid2 = left2 + (right2 - left2) / 2;
        size_t diff = nums1.size() + nums2.size() - mid1 * 2 - mid2 * 2 + 2;
        for (size_t i = 0; i < diff; ++i)
        {
            if (mid1 < nums1.size() && mid2 < nums2.size() &&
                nums1[mid1 + 1] - nums1[mid1] < nums2[mid2 + 1] - nums2[mid2])
                ++mid1;
            else
                ++mid2;
        }

        return (nums1[mid1] + nums2[mid2]) / 2;
    }

private:
    double findMedian(const vector<int> &nums)
    {
        size_t mid = nums.size() / 2;
        if (nums.size() % 2 != 0)
            return nums[mid];
        else
            return (nums[mid - 1] + nums[mid]) / 2;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums1{1, 2, 3, 4, 5}, nums2{3, 4};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    system("pause");
    return 0;
}
