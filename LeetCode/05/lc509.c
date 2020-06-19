/* lc509.c */

/* LeetCode 509. Fibonacci Number `E` */
/* 1sk | 100% | 6' */
/* A~0f19 */

int fib(int N)
{
    if (N == 0)
        return 0;

    int res = 1;
    int prev = 0;
    for (int i = 1; i < N; ++i)
    {
        int tmp = res;
        res = res + prev;
        prev = tmp;
    }

    return res;
}
