# LeetCode 788. Rotated Digits 
# 1sk | 96% | 8'
# A~0h13

class Solution:
    def rotatedDigits(self, N: int) -> int:
        ans = 0
        for i in range(N+1):
            s = str(i)
            if "3" in s or "4" in s or "7" in s:
                continue
            if "2" in s or "5" in s or "6" in s or "9" in s:
                ans += 1

        return ans
