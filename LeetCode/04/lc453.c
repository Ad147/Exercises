/* lc453.c */

/* LeetCode 453. Minimum Moves to Equal Array Elements `E` */
/* acc | 70%* | 6' */
/* A~0f11 */

int minMoves(int *nums, int numsSize)
{
    long sum = 0;
    long min = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (nums[i] < min)
            min = nums[i];
    }

    return sum - min * numsSize;
}
