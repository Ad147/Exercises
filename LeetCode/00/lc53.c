/* lc53.c */

/* LeetCode 53. Maximum Subarray `E` */
/* acc | 97% | 32' */
/* A~0d07 */

int maxSubArray(int *nums, int numsSize)
{
    int ret = nums[0], sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (ret < sum)
            ret = sum;
        if (sum < 0)
            sum = 0;
    }

    return ret;
}
