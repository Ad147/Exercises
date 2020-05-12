/* lc231.c */

/* LeetCode 231. Power of Two `E` */
/* acc | 100% | 11' */
/* A~0e12 */

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    while (n != 1)
    {
        if (n & 1 == 1)
            return false;

        n >>= 1;
    }

    return true;
}
