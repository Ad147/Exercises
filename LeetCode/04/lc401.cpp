// lc401.cpp

// LeetCode 401. Binary Watch `E`
// 1sk | 100% | 35'
// A~0e30

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;

        for (int h = 0; h < 12; h++)
        {
            int hCnt = count(h);
            for (int m = 0; m < 60; m++)
            {
                int mCnt = count(m);
                if (hCnt + mCnt == num)
                    res.push_back(to_string(h) + ':' + (m < 10 ? '0' + to_string(m) : to_string(m)));
            }
        }

        return res;
    }

private:
    int count(int n)
    {
        int res = 0;

        while (n)
        {
            res += n & 1;
            n >>= 1;
        }

        return res;
    }
};