# lc693.py

# LeetCode 693. Binary Number with Alternating Bits `E`
# acc | 99% | 16'
# A~0g27

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = (n >> 1) ^ n
        return (n+1) & n == 0
