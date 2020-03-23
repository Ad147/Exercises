// lc169.cpp

// LeetCode 169 Majority Element `E`
// A~0c23
// 1sk | 99% | 10'

static int _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        map<int, size_t> count;
        for (int n : nums)
            count[n]++;

        size_t maxcnt = 0;
        int majorityElement = -1;
        for (auto itr = count.cbegin(); itr != count.cend(); itr++)
            if (itr->second > maxcnt)
            {
                maxcnt = itr->second;
                majorityElement = itr->first;
            }

        return majorityElement;
    }
};