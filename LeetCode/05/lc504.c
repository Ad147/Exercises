/* lc504.c */

/* LeetCode 504. Base 7 `E` */
/* 1sk | 100% | 28' */
/* A~0f18 */

char *convertToBase7(int num)
{
    int negative = 0;
    if (num < 0)
    {
        negative = 1;
        num = -num;
    }

    char *res = malloc(sizeof(char) * 256);
    int len = 0;
    if (num == 0)
        res[len++] = '0';
    while (num)
    {
        res[len++] = num % 7 + '0';
        num /= 7;
    }
    if (negative)
        res[len++] = '-';
    res[len] = 0;

    for (int i = 0; i < len; ++i)
    {
        char tmp = res[i];
        res[i] = res[--len];
        res[len] = tmp;
    }

    return res;
}
