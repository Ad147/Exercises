// lc38.c

// LeetCode 38. Count and Say `E`
// acc | 100% | 32'
// A~0d06

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        vector<int> prev{1}, tmp;
        for (int j = 1; j < n; j++)
        {
            tmp.clear();
            int cnt = 1;
            for (int i = 0; i < prev.size(); i++)
                if (i + 1 == prev.size() || prev[i + 1] != prev[i])
                {
                    tmp.push_back(cnt);
                    tmp.push_back(prev[i]);
                    cnt = 1;
                }
                else
                    cnt++;

            prev = tmp;
        }

        string ret;
        for (auto i : prev)
            ret += to_string(i);
        return ret;
    }
};
