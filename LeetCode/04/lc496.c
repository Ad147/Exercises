/* lc496.c */

/* LeetCode 496. Next Greater Element I `E` */
/* 1sk | 100% | 14' */
/* A~0f16 */

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int *res = malloc(sizeof(int) * nums1Size);

    for (int i = 0; i < nums1Size; ++i)
    {
        int j = 0;
        while (j < nums2Size && nums1[i] != nums2[j])
            ++j;

        int k = j + 1;
        while (k < nums2Size && nums2[j] > nums2[k])
            ++k;

        res[i] = k == nums2Size ? -1 : nums2[k];
    }

    *returnSize = nums1Size;
    return res;
}
