/* lc389.c */

/* LeetCode 389. Find the Difference `E` */
/* 1sk | 100% | 4' */
/* A~0e28 */

char findTheDifference(char *s, char *t)
{
    int count[26] = {0};
    while (*s)
        count[*s++ - 'a']++;
    while (*t)
        count[*t++ - 'a']--;

    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return 'a' + i;

    return 0;
}
