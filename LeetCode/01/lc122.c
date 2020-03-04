/* lc122.c */

/* LeetCode 122 Best Time to Buy and Sell Stock II `E` */
/* A~0c04 */
/* acc | 100% | 17' */

int maxProfit(int *prices, int pricesSize)
{
    if (!prices || !pricesSize)
        return 0;

    int profit = 0;
    for (int i = 1; i < pricesSize; i++)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];

    return profit;
}
