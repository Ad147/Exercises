// LC033-SearchInRotatedSortedArray.cpp
// Ad
// Init: 19Sep12

// Difficulty: Medium
// Status: 16/196
// Time: 60'
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
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;

        int pivot = findPivot(nums), size = nums.size();
        int left = pivot, right = (pivot == 0) ? (size - 1) : (pivot - 1);
        while (left != right)
        {
            int mid = calcMid(left, right, size);
            if (nums[mid] < target)
                left = (mid + 1) % size;
            else if (nums[mid] > target)
            {
                int newRight = (mid - 1 >= 0) ? mid - 1 : mid - 1 + size;
                if (right != newRight)
                    right = newRight;
                else
                    break;
            }
            else
                return mid;
        }

        if (nums[left] == target)
            return left;
        else
            return -1;
    }

private:
    int findPivot(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2)
            return (nums[0] < nums[1]) ? 0 : 1;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid - 1])
                return mid;
            else if (nums[mid] > nums[mid + 1])
                return mid + 1;
            else if (nums[mid] < nums[left])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid;
            else
                throw exception();
        }

        throw exception();
    }

    int calcMid(int left, int right, int size)
    {
        if (left < right)
            return left + (right - left) / 2;
        else if (left > right)
            return (left + (right - left + size) / 2) % size;
        else
            throw exception();
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    // vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    vector<int> nums{1, 3};
    vector<int> targets{0, 1, 2, 3, 4, 5, 6, 7};

    for (auto target : targets)
        cout << sol.search(nums, target) << endl;

    system("pause");
    return 0;
}
