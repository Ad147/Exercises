// lc219.cpp

// LeetCode 219. Contains Duplicate II `E`
// 1sk | 83%* | 13'
// A~0e09

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++)
        {
            auto &prev = ht[nums[i]];
            if (prev != 0 && (i - prev) < k)
                return true;
            else
                prev = i + 1;
        }

        return false;
    }
};
