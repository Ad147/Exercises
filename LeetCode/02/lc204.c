/* LeetCode 204. Count Primes `E` */
/* acc | 25% | 10' */
/* A~1e13 */

int countPrimes(int n)
{
    if (n < 3)
        return 0;

    /* int primes[50000]; */
    /* primes[0] = 2; */
    int cnt = 1;
    for (int i = 3; i < n; i += 2)
    {
        int flag = 1;
        for (int j = 3; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            cnt++;
    }

    return cnt;
}
