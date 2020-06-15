/* lc482.c */

/* LeetCode 482. License Key Formatting `E` */
/* acc | 81%* | 32' */
/* A~0f15 */

char *licenseKeyFormatting(char *S, int K)
{
    int charCnt = 0;
    for (int i = 0; S[i]; ++i)
        if (S[i] != '-')
            ++charCnt;

    int firstLen = charCnt % K;
    firstLen = firstLen == 0 ? K : firstLen;
    int groupNum = charCnt / K + (firstLen != K);
    int resLen = charCnt + groupNum - 1;
    char *res;
    if (charCnt == 0)
    {
        res = malloc(sizeof(char) * 1);
        res[0] = 0;
        return res;
    }
    else
        res = malloc(sizeof(char) * (resLen + 1));

    for (int i = 0, j = 0; i < resLen; ++i, ++j)
    {
        if ((i - firstLen) % (K + 1) == 0)
            res[i++] = '-';

        while (S[j] == '-')
            ++j;

        res[i] = toupper(S[j]);
    }

    res[resLen] = 0;
    return res;
}
