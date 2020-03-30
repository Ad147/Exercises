// lc1030.cpp

// LeetCode 1030. Matrix Cells in Distance Order `E`
// 1sk | 60%* | 53'
// A~0c30

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> ret;
        if (R < 1 || C < 1)
            return ret;

        ret.push_back({r0, c0});
        for (int dist = 1; ret.size() != R * C; dist++)
        {
            int rdist = dist, cdist = 0;
            while (rdist > 0)
            {
                int r = r0 + rdist, c = c0 + cdist;
                if (r < R && c < C)
                    ret.push_back({r, c});

                r = r0 - rdist;
                c = c0 - cdist;
                if (r >= 0 && c >= 0)
                    ret.push_back({r, c});

                r = r0 - cdist;
                c = c0 + rdist;
                if (r >= 0 && c < C)
                    ret.push_back({r, c});

                r = r0 + cdist;
                c = c0 - rdist;
                if (r < R && c >= 0)
                    ret.push_back({r, c});

                rdist--;
                cdist++;
            }
        }

        return ret;
    }
};
