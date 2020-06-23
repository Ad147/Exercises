// lc532.cpp

// LeetCode 532. K-diff Pairs in an Array `E`
// 1sk | 93% | 11'
// A~0f23

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                int diff = nums[j] - k - nums[i];
                if (diff < 0)
                    continue;
                else
                {
                    if (diff == 0)
                        res++;

                    break;
                }
            }
        }

        return res;
    }
};
