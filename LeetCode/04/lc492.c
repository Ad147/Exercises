/* lc492.c */

/* LeetCode 492. Construct the Rectangle `E` */
/* acc | 100% | 20' */
/* A~0d02 */

int *constructRectangle(int area, int *returnSize)
{
    int *ret = calloc(2, sizeof(int));
    if (area < 1)
        return NULL;

    for (int w = 1; w * w <= area; w++)
        if (area % w == 0)
        {
            ret[0] = area / w;
            ret[1] = w;
        }

    *returnSize = 2;
    return ret;
}
