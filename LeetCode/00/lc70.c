/* lc70.c */

/* LeetCode 70. Climbing Stairs `E` */
/* acc | 100% | 9' */
/* A~0d09 */

int climbStairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int prev1 = 1, prev2 = 2, ans = 3;
    for (int i = 3; i < n; i++)
    {
        prev1 = prev2;
        prev2 = ans;
        ans = prev1 + prev2;
    }

    return ans;
}
