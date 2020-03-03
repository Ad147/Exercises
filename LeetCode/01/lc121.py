# lc121.py

# LeetCode 121 Best Time to Buy and Sell Stock `E`
# A~0c03
# acc | 99%

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice, maxProfit = 65536, 0
        for i in prices:
            if i < minPrice:
                minPrice = i
            elif i - minPrice > maxProfit:
                maxProfit = i - minPrice
        return maxProfit
