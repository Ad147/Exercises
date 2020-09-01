# LeetCode 868. Binary Gap `E`
# 1sk | 97% | 13'
# A~0i01

class Solution:
    def binaryGap(self, N: int) -> int:
        if not N:
            return 0
        ans = 0
        while N & 1 == 0:
            N >>= 1
        cnt = 0
        while N:
            if N & 1:
                ans = max(ans, cnt)
                cnt = 1
            else:
                cnt += 1
            N >>= 1
        return ans
