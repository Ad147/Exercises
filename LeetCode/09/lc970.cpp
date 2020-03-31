// lc970.cpp

// LeetCode 970. Powerful Integers `E`
// acc | 100% | 41'
// A~0c31

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> ret;
        if (bound < 2)
            return ret;
        else if (x == 1 && y == 1)
            return vector<int>{2};

        unordered_set<int> ht;
        for (int i = 0;; i++)
        {
            int res = pow(x, i);
            if (res > bound)
                break;

            int sum = 0;
            for (int j = 0;; j++)
            {
                sum = res + pow(y, j);
                if (sum > bound)
                    break;
                ht.insert(sum);
                if (y == 1)
                    break;
            }

            if (x == 1 && sum > bound)
                break;
        }

        for (auto i : ht)
            ret.push_back(i);
        return ret;
    }
};
