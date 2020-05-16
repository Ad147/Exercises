/* lc242.c */

/* LeetCode 242. Valid Anagram `E` */
/* 1sk | 78%* | 13' */
/* A~0e16 */

bool isAnagram(char *s, char *t)
{
    int count[256] = {0};
    char *sp = s;
    while (*sp)
        count[*sp++]++;

    char *tp = t;
    while (*tp)
        if (count[*tp] == 0)
            return false;
        else
            count[*tp++]--;

    if (sp - s == tp - t)
        return true;
    else
        return false;
}
