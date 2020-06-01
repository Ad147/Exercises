/* lc405.c */

/* LeetCode 405. Convert a Number to Hexadecimal `E` */
/* acc | 100% | 26' */
/* A~0f01 */

char *toHex(int num)
{
    char *res = malloc(sizeof(char) * 64);

    if (num == 0)
    {
        res[0] = '0';
        res[1] = 0;
        return res;
    }

    unsigned unum = num;
    char *end = res;
    while (unum)
    {
        unsigned remainder = unum % 16;
        *end++ = remainder < 10 ? '0' + remainder : 'a' + remainder - 10;
        unum /= 16;
    }

    *end-- = 0;
    char *beg = res;
    while (beg < end)
    {
        char tmp = *beg;
        *beg++ = *end;
        *end-- = tmp;
    }

    return res;
}
