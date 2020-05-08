// lc217.cpp

// LeetCode 217. Contains Duplicate `E`
// acc | 83%* | 8'
// A~0e08

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.empty())
            return false;

        sort(nums.begin(), nums.end());

        int prev = nums[0] - 1;
        for (auto i : nums)
        {
            if (i == prev)
                return true;
            else
                prev = i;
        }

        return false;
    }
};
