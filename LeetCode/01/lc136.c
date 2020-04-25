/* lc136.c */

/* LeetCode 136. Single Number `E` */
/* acc | 94% | 36' */
/* A~0d25 */

int singleNumber(int *nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
        nums[i] ^= nums[i - 1];

    return nums[numsSize - 1];
}
