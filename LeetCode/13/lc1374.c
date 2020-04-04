/* lc1374.c */

/* LeetCode 1374. Generate a String With Characters That Have Odd Counts `E` */
/* 1sk | 100% | 7' */
/* A~0d04 */

char *generateTheString(int n)
{
    char *ret = calloc(n + 1, sizeof(char));

    int beg = 0;
    if (n % 2 == 0)
    {
        ret[0] = 'a';
        beg = 1;
    }
    for (int i = beg; i < n; i++)
        ret[i] = 'b';

    ret[n] = '\0';
    return ret;
}
