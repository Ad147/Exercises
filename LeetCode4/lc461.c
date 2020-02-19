/* lc461.c */

/* LeetCode 461 Hamming Distance `E` */
/* A~0b19 */
/* acc | 29' | rt53%* | mu70% */

int hammingDistance(int x, int y)
{
    int res = x ^ y;
    int cnt = 0;
    for (int i = 0; i < 31; i++)
    {
        if (res & 1)
            cnt++;

        res >>= 1;
    }

    return cnt;
}
