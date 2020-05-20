/* lc268.c */

/* LeetCode 268. Missing Number `E` */
/* acc | 89%* | 48' */
/* A~0e20 */

/* XOR solution */
int missingNumber(int *nums, int numsSize)
{
    int miss = numsSize;
    for (int i = 0; i < numsSize; i++)
        miss ^= i ^ nums[i];

    return miss;
}

/* Gauss formula solution */
int missingNumber(int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    return numsSize * (numsSize + 1) / 2 - sum;
}
