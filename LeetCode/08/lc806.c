/* lc806.c */

/* LeetCode 806 Number of Lines To Write String `E` */
/* A~0b21 */
/* osk | 27' | rt100% | mu100% */

int *numberOfLines(int *widths, int widthsSize, char *S, int *returnSize)
{
    int lncnt = 1, chcnt = 0;
    for (char *p = S; *p; p++)
    {
        int newchs = widths[*p - 'a'];
        if ((chcnt + newchs) > 100)
        {
            lncnt++;
            chcnt = 0;
        }
        chcnt += newchs;
    }

    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = lncnt;
    ret[1] = chcnt;
    return ret;
}
