/* lc1323.c */

/* LeetCode 1323 Maximum 69 Number `E` */
/* A~0b24 */
/* osk | 13' | rt100% | mu100% */

int maximum69Number(int num)
{
    if (num < 1 || num > 9999)
        return -1;
    if (num == 9999)
        return 9999;

    int digits[4] = {0};
    for (int i = 3; num; i--, num /= 10)
        digits[i] = num % 10;

    for (int i = 0; i < 4; i++)
        if (digits[i] == 6)
        {
            digits[i] = 9;
            break;
        }

    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        ret *= 10;
        ret += digits[i];
    }

    return ret;
}
