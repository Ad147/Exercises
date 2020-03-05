/* lc475.c */

/* LeetCode 475 Heaters `E` */
/* A~0c05 */
/* acc | 100% | 70' */

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findRadius(int *houses, int housesSize, int *heaters, int heatersSize)
{
    if (!houses || !housesSize || !heaters || !heatersSize)
        return -1;

    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);

    int radius = -1;
    int lastJ = 0;
    for (int i = 0; i < housesSize; i++)
    {
        int minDist = INT_MAX;
        for (int j = lastJ; j < heatersSize; j++)
        {
            int dist = abs(houses[i] - heaters[j]);
            if (dist < minDist)
            {
                minDist = dist;
                lastJ = j;
            }
            else if (dist > minDist)
                break;

            if (minDist == 0)
                break;
        }

        if (minDist > radius)
            radius = minDist;
    }

    return radius;
}
