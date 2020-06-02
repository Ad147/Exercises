/* lc409.c */

/* LeetCode 409. Longest Palindrome `E` */
/* 1sk | 100% | 11' */
/* A~0f02 */

int longestPalindrome(char *s)
{
    if (!s)
        return 0;

    int count[52] = {0};
    do
    {
        if (*s < 'a')
            count[*s - 'A']++;
        else
            count[*s - 'a' + 26]++;
    } while (*++s);

    int res = 0;
    int odd = 0;
    for (int i = 0; i < 52; i++)
    {
        if (count[i] == 0)
            continue;

        if (count[i] % 2 != 0)
        {
            res += count[i] - 1;
            odd = 1;
        }
        else
            res += count[i];
    }

    return res + odd;
}
