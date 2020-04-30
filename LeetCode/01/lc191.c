/* lc191.c */

/* LeetCode 191. Number of 1 Bits `E` */
/* 1sk | 100% | 3' */
/* A~0d30 */

int hammingWeight(uint32_t n)
{
    int res = 0;
    while (n)
    {
        res += n & 1;
        n >>= 1;
    }

    return res;
}
