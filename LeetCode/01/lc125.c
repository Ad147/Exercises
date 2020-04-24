/* lc125.c */

/* LeetCode 125. Valid Palindrome `E` */
/* acc | 100% | 18' */
/* A~0d24 */

bool isPalindrome(char *s)
{
    const int len = strlen(s);
    int i = 0, j = len - 1;
    while (1)
    {
        while (i < len && !isalnum(s[i]))
            i++;
        while (j >= 0 && !isalnum(s[j]))
            j--;
        if (i >= j)
            return true;

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }

    return true;
}
