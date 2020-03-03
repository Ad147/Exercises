/* lc121.c */

/* LeetCode 121 Best Time to Buy and Sell Stock `E` */
/* A~0c03 */
/* acc | 99% | 23' */

int maxProfit(int *prices, int pricesSize)
{
    int minPrice = 65536, maxProfit = 0;
    for (int i = 0; i < pricesSize; i++)
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;

    return maxProfit;
}
