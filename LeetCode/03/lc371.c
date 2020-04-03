/* lc371.c */

/* LeetCode 371. Sum of Two Integers `E` */
/* acc | 100% | 10' */
/* A~0d03 */

int getSum(int a, int b)
{
    int c = 0;
    while (b != 0)
    {
        c = a & b;
        a ^= b;
        b = (unsigned)c << 1;
    }

    return a;
}
