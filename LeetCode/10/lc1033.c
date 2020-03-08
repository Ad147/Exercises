/* lc1033.c */

/* LeetCode 1033 Moving Stones Until Consecutive `E` */
/* A~0c08 */
/* 1sk | 100% | 24' */

int *numMovesStones(int a, int b, int c, int *returnSize)
{
    int *ret = (int *)calloc(sizeof(int), 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;

    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100)
        return ret;

    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a > c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b > c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }

    if (a + 1 == b && b + 1 == c)
    {
        ret[0] = ret[1] = 0;
        return ret;
    }
    else if (a + 1 == b || b + 1 == c || a + 2 == b || b + 2 == c)
        ret[0] = 1;
    else
        ret[0] = 2;

    ret[1] = c - a - 2; /* = (b - a - 1) + (c - b - 1) */

    return ret;
}
