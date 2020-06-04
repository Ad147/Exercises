/* lc415.c */

/* LeetCode 415. Add Strings `E` */
/* 1sk | 100% | 42' */
/* A~0f04 */

char *addStrings(char *num1, char *num2)
{
    int n1sz = 0, n2sz = 0;
    char *n1p = num1, *n2p = num2;
    while (*n1p || *n2p)
    {
        if (*n1p)
        {
            n1sz++;
            n1p++;
        }
        if (*n2p)
        {
            n2sz++;
            n2p++;
        }
    }

    int resSz = (n1sz > n2sz ? n1sz : n2sz) + 1;
    char *res = malloc(sizeof(char) * resSz + 1);
    res[resSz] = 0;

    int flag = 0;
    while (resSz)
    {
        int sum;
        if (n1sz == 0 && n2sz == 0)
            sum = flag;
        else if (n1sz == 0)
            sum = num2[--n2sz] - '0' + flag;
        else if (n2sz == 0)
            sum = num1[--n1sz] - '0' + flag;
        else
            sum = num1[--n1sz] - '0' + num2[--n2sz] - '0' + flag;

        if (sum > 9)
        {
            res[--resSz] = sum - 10 + '0';
            flag = 1;
        }
        else
        {
            res[--resSz] = sum + '0';
            flag = 0;
        }
    }

    return res[0] == '0' ? res + 1 : res;
}