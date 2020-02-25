/* lc784.c */

/* LeetCode 784 Letter Case Permutation `E` */
/* A~0b25 */
/* osk | 61' | rt97% | mu100% */

char **letterCasePermutation(char *S, int *returnSize)
{
    int letterCnt = 0;
    for (int i = 0; S[i]; i++)
        if (isalpha(S[i]))
            letterCnt++;
    *returnSize = pow(2, letterCnt);
    char **ret = (char **)calloc(*returnSize, sizeof(char *));
    if (!ret)
        return NULL;

    int arrIdx = 0;
    appendStr(ret, &arrIdx, S, 0);

    return ret;
}

int appendStr(char **ca, int *arrIdx, char *str, int strIdx)
{
    while (str[strIdx] && !isalpha(str[strIdx]))
        strIdx++;

    if (!str[strIdx])
    {
        ca[(*arrIdx)++] = str;
        return 0;
    }

    char *lower = (char *)malloc(strlen(str) + 1);
    char *upper = (char *)malloc(strlen(str) + 1);
    strcpy(lower, str);
    strcpy(upper, str);
    lower[strIdx] = tolower(lower[strIdx]);
    upper[strIdx] = toupper(upper[strIdx]);
    strIdx++;
    if (appendStr(ca, arrIdx, lower, strIdx))
    {
        free(lower);
        lower = NULL;
    }
    if (appendStr(ca, arrIdx, upper, strIdx))
    {
        free(upper);
        upper = NULL;
    }

    return 1;
}
