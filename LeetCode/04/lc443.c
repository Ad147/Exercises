/* lc443.c */

/* LeetCode 443. String Compression `E` */
/* 1sk | 83%* | 47' */
/* A~0f08 */

int compress(char *chars, int charsSize)
{
    int len = 0;
    for (int i = 0; i < charsSize;)
    {
        int cnt = 1;
        int j = i + 1;
        while (j < charsSize)
            if (chars[j] == chars[i])
            {
                cnt++;
                j++;
            }
            else
                break;

        chars[len++] = chars[i];
        if (cnt != 1)
        {
            char digits[5];
            sprintf(digits, "%d", cnt);
            for (int n = 0; digits[n]; n++)
                chars[len++] = digits[n];
        }

        i = j;
    }

    return len;
}
