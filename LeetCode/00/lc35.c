/* lc35.c */

/* LeetCode 35. Search Insert Position `E` */
/* 1sk | 82% | 10' */
/* A~0d06 */

int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize, mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (target < nums[mid])
            right = mid;
        else
            return mid;
    }

    if (nums[mid] < target)
        return left;
    else
        return right;
}
