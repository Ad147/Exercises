/* lc258.c */

/* LeetCode 258. Add Digits `E` */
/* 1sk | 100% | 10' */
/* A~0e18 */

int addDigits(int num)
{
    while (num > 9)
    {
        int sum = num % 10;
        while (num /= 10)
            sum += num % 10;

        num = sum;
    }

    return num;
}

/* O(1) answer */
/* 
int addDigits(int num)
{
    if (num == 0)
        return 0;
    if (num % 9 == 0)
        return 9;
    return num % 9;
}
 */
