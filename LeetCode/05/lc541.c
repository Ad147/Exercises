/* lc541.c */

/* LeetCode 541. Reverse String II `E` */
/* acc | 100% | 30' */
/* A~0f25 */

void reverse(char *left, char *right);

char *reverseStr(char *s, int k)
{
    char *left = s, *right = s;
    int len = strlen(s);
    while (left < s + len)
    {
        right = left;
        while (right - left < k - 1 && right < s + len - 1)
            ++right;

        reverse(left, right);

        left += k * 2;
    }

    return s;
}

void reverse(char *left, char *right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;

        ++left;
        --right;
    }
}
