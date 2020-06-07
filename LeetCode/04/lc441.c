/* lc441.c */

/* LeetCode 441. Arranging Coins `E` */
/* acc | 100% | 21' */
/* A~0f07 */

int arrangeCoins(int n)
{
    long res = sqrt((double)n * 2) + 1;
    while (res > 0)
    {
        if ((res + 1) * res / 2 <= n && (res + 2) * (res + 1) / 2 > n)
            return res;
        else
            res--;
    }

    return 0;
}
