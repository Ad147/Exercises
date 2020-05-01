/* lc202.c */

/* LeetCode 202. Happy Number `E` */
/* 1sk | 100% | 15' */
/* A~0e01 */

bool isHappy(int n)
{
    int digits[100];
    int cnt;
    for (int loop = 0; loop < 100; loop++)
    {
        for (cnt = 0; n != 0; cnt++, n /= 10)
            digits[cnt] = n % 10;

        for (int i = 0; i < cnt; i++)
            n += digits[i] * digits[i];

        if (n == 1)
            return true;
    }

    return false;
}
