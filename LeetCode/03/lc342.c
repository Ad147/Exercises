/* lc342.c */

/* LeetCode 342. Power of Four `E` */
/* acc | 100% | 16' */
/* A~0e25 */

bool isPowerOfFour(int num)
{
    if (num <= 0)
        return false;

    return ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
}
