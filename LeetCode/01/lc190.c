/* lc190.c */

/* LeetCode 190. Reverse Bits `E` */
/* 1sk | 100% | 24' */
/* A~0d29 */

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;

    for (int i = 0; i < 32; i++, n >>= 1)
        res = (res << 1) | (n & 1);

    return res;
}
