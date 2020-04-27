/* lc171.c */

/* LeetCode 171. Excel Sheet Column Number `E` */
/* 1sk | 100% | 5' */
/* A~0d27 */

int titleToNumber(char *s)
{
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        res *= 26;
        res += s[i] - 'A' + 1;
    }

    return res;
}
