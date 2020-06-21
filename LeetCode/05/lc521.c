/* lc521.c */

/* LeetCode 521. Longest Uncommon Subsequence I `E` */
/* acc | 100% | 10' */
/* A~0f21 */

int findLUSlength(char *a, char *b)
{
    int equal = 1;
    int la = 0;
    int lb = 0;
    while (*a && *b)
    {
        if (equal && *a != *b)
            equal = 0;

        ++la;
        ++lb;
        ++a;
        ++b;
    }
    while (*a++)
        ++la;
    while (*b++)
        ++lb;

    if (la == lb && equal)
        return -1;
    else
        return la > lb ? la : lb;
}
