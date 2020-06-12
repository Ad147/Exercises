// lc455.cpp

// LeetCode 455. Assign Cookies `E`
// 1sk | 90% | 12'
// A~0f12

static int _ = []() { std::ios::sync_with_stdio(false); return 0; }();

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int res = 0;
        int i = 0;
        for (auto cookie : s)
        {
            while (i < g.size() && cookie < g[i])
                i++;

            if (i < g.size())
                res++;
            else
                break;

            i++;
        }

        return res;
    }
};
