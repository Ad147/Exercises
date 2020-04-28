/* lc172.c */

/* LeetCode 172. Factorial Trailing Zeroes `E` */
/* acc | 100% | 11' */
/* A~0d28 */

int trailingZeroes(int n)
{
    int res = 0;
    while (n /= 5)
        res += n;

    return res;
}
