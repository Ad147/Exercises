// lc566.cpp

// LeetCode 566. Reshape the Matrix `E`
// acc | 94% | 49'
// A~0f30

int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        if (nums.size() * nums[0].size() != r * c)
            return nums;

        vector<vector<int>> res(r, vector<int>(c));
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[0].size(); j++)
            {
                res[cnt / c][cnt % c] = nums[i][j];
                cnt++;
            }

        return res;
    }
};
