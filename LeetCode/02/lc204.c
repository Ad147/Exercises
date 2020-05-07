/* lc204.c */

/* LeetCode 204. Count Primes `E` */
/* 17/20 | | 30' */
/* A~0e06 */

int countPrimes(int n)
{
    if (n < 3)
        return 0;

    int primes[50000];
    primes[0] = 2;
    int cnt = 1;
    for (int i = 3; i < n; i += 2)
    {
        int flag = 1;
        for (int j = 1; j < cnt; j++)
        {
            if (i % primes[j] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            primes[cnt++] = i;
    }

    return cnt;
}
