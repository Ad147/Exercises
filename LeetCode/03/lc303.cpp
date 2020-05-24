// lc303.cpp

// LeetCode 303. Range Sum Query - Immutable `E`
// 1sk | 100% | 10'
// A~0e24

static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class NumArray
{
private:
    vector<int> sums;

public:
    NumArray(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j)
    {
        if (i == 0)
            return sums[j];
        else
            return sums[j] - sums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
