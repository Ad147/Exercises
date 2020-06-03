/* lc414.c */

/* LeetCode 414. Third Maximum Number `E` */
/* acc | 92% | 17' */
/* A~0f03 */

int thirdMax(int *nums, int numsSize)
{
    long max1, max2, max3;
    max1 = max2 = max3 = -LONG_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] != max1)
        {
            if (nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] != max2 && nums[i] > max3)
                max3 = nums[i];
        }
    }

    if (max3 == -LONG_MAX)
        return max1;
    else
        return max3;
}
