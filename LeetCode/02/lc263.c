/* lc263.c */

/* LeetCode 263. Ugly Number `E` */
/* 1sk | 100% | 6' */
/* A~0e19 */

bool isUgly(int num)
{
    if (num < 1)
        return false;

    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;

    if (num == 1)
        return true;
    else
        return false;
}
