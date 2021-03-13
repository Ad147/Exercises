/* lc198.c */

/* LeetCode 198. House Robber `M` */
/* 55/69 |  | 60' */
/* A~0d30 */

int rob(int *nums, int numsSize)
{
    int res = 0;

    for (int i = 0; i < numsSize; i += 2)
    {
        if ((i < numsSize - 3 &&
             ((nums[i] + nums[i + 2] >= nums[i + 1] + nums[i + 3]) ||
              (nums[i] + nums[i + 3] >= nums[i + 1] + nums[i + 3]))) ||
            (i == numsSize - 3 && nums[i] + nums[i + 2] > nums[i + 1]) ||
            (i == numsSize - 2 && nums[i] > nums[i + 1]) ||
            (i == numsSize - 1))
            res += nums[i];
        else
            res += nums[i++ + 1];
    }

    return res;
}
