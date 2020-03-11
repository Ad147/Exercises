// lc506.cpp

// LeetCode 506 Relative Ranks `E`
// A~0c11
// acc | 99% | 40'

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<string> ret(nums.size());
        if (nums.empty())
            return ret;

        vector<int> index(nums.size());
        for (int i = 0; i < index.size(); i++)
            index[i] = i;
        sort(index.begin(), index.end(), [&nums](int x, int y) { return nums[x] > nums[y]; });

        for (int i = 0; i < index.size(); i++)
        {
            string rank;
            if (i == 0)
                rank = "Gold Medal";
            else if (i == 1)
                rank = "Silver Medal";
            else if (i == 2)
                rank = "Bronze Medal";
            else
                rank = to_string(i + 1);

            ret[index[i]] = rank;
        }

        return ret;
    }
};