/* lc299.c */

/* LeetCode 299. Bulls and Cows `E` */
/* acc | 100% | 51' */
/* A~0e23 */

char *getHint(char *secret, char *guess)
{
    int digitCount[10] = {0};
    int bullCount = 0;
    int len = 0;
    while (*secret)
    {
        len++;
        if (*secret == *guess)
            bullCount++;
        digitCount[*secret++ - '0']++;
        digitCount[*guess++ - '0']--;
    }

    int distinct = 0;
    for (int i = 0; i < 10; i++)
    {
        if (digitCount[i] > 0)
            distinct += digitCount[i];
    }

    int cow = len - distinct - bullCount;
    /* char *res = malloc(sizeof(char) * (int)(ceil(log10(bullCount)) + ceil(log10(cow)) + 30)); */
    char *res = malloc(sizeof(char) * 100);
    sprintf(res, "%dA%dB", bullCount, cow);

    return res;
}
