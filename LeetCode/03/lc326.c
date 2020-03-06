/* lc326.c */

/* LeetCode 326 Power of Three `E` */
/* A~0c06 */
/* acc | 80%* | 32' */

/* solution without using loop / recursion */
int isPowerOfThree(int n)
{
    return n > 0 && 1162261467 % n == 0; /* 3^19, max power of 3 of type int */
}

/* solution using loop */
int isPowerOfThree(int n)
{
    if (n <= 0)
        return 0;

    while (n != 1)
    {
        if (n % 3 != 0)
            return 0;

        n /= 3;
    }

    return 1;
}
