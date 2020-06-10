/* lc448.c */

/* LeetCode 448. Find All Numbers Disappeared in an Array `E` */
/* acc | 80%* | 29' */
/* A~0f10 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *hash = calloc(numsSize + 1, sizeof(int));
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[nums[i]] == 0)
        {
            hash[nums[i]] = 1;
            cnt++;
        }
    }

    int *res = malloc(sizeof(int) * (numsSize - cnt));
    *returnSize = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (hash[i] == 0)
            res[(*returnSize)++] = i;
        if (*returnSize == numsSize - cnt)
            break;
    }

    return res;
}
