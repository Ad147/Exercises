/* lc476.c */

/* LeetCode 476. Number Complement `E` */
/* 1sk | 100% | 13' */
/* A~0f14 */

int findComplement(int num)
{
    int comp = ~num;
    int flag = 0;
    while (num)
    {
        flag <<= 1;
        flag |= 1;
        num >>= 1;
    }

    return comp & flag;
}
