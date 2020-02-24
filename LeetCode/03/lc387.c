/* lc387.c */

/* LeetCode 387 First Unique Character in a String `E` */
/* A~0b18 */
/* osk~16' / rt>92% / mu>67% */

int firstUniqChar(char *s)
{
    int cnt[26] = {0};
    for (char *p = s; *p; p++)
        cnt[*p - 'a']++;

    for (char *p = s; *p; p++)
        if (cnt[*p - 'a'] == 1)
            return p - s;

    return -1;
}
