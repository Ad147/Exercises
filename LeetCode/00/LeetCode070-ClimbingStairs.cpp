// LeetCode070-ClimbingStairs.cpp
// Ad
// You are climbing a stair case.
// It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

#include <iostream>

// solution ====================================================================

class Solution
{
  public:
    int climbStairs(int n)
    {
        climbStairsAux(n);

        return cnt;
    }

  private:
    void climbStairsAux(int n)
    {
        if (n == 0)
        {
            ++cnt;
            return;
        }
        else if (n < 0)
            return;
        else
        {
            climbStairs(n - 1);
            climbStairs(n - 2);
        }
    }

    int cnt;
};

// main ========================================================================

int main()
{
    int i = 44;
    Solution sln;
    std::cout << sln.climbStairs(i) << std::endl;

    system("pause");
    return 0;
}
