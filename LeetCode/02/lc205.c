/* lc205.c */

/* LeetCode 205. Isomorphic Strings `E` */
/* acc | 100% | 47' */
/* A~0e07 */

bool isIsomorphic(char *s, char *t)
{
    int sMap[256] = {0}, tMap[256] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (sMap[s[i]] != tMap[t[i]])
            return false;

        sMap[s[i]] = tMap[t[i]] = i + 1;
    }

    return true;
}
