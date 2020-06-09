// lc447.cpp

// LeetCode 447. Number of Boomerangs `E`
// acc | 97% | 42'
// A~0f09

static int x = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;
        vector<int> dists(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                dists[j] = a * a + b * b;
            }

            sort(dists.begin(), dists.end());
            for (int j = 2; j < dists.size(); j++)
            {
                int cnt = 1;
                while (j < dists.size() && dists[j] == dists[j - 1])
                {
                    j++;
                    cnt++;
                }
                res += cnt * (cnt - 1);
            }
        }

        return res;
    }
};
