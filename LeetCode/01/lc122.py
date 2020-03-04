# lc122.py

# LeetCode 122 Best Time to Buy and Sell Stock II `E`
# A~0c04
# acc | 78%


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        profit = 0
        for i in range(len(prices) - 1):
            if prices[i + 1] > prices[i]:
                profit += prices[i + 1] - prices[i]

        return profit
