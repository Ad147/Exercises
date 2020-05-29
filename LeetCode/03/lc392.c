/* lc392.c */

/* LeetCode 392. Is Subsequence `E` */
/* 1sk | 100% | 9' */
/* A~0e29 */

bool isSubsequence(char *s, char *t)
{
    while (*s)
    {
        if (*t == 0)
            return false;

        if (*s == *t++)
            s++;
    }

    return true;
}
