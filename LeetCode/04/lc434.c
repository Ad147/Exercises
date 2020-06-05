/* lc434.c */

/* LeetCode 434. Number of Segments in a String `E` */
/* acc | 100% | 13' */
/* A~0f05 */

int countSegments(char *s)
{
    if (*s == 0)
        return 0;

    int cnt = 0;
    int inChar = 0;
    while (*s)
    {
        if (*s++ != ' ')
            inChar = 1;
        else if (inChar)
        {
            cnt++;
            inChar = 0;
        }
    }

    return cnt + inChar;
}
