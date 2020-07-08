# lc598.py

# LeetCode 598. Range Addition II `E`
# 1sk | 22% | 6'
# A~0g08


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        mina, minb = m, n
        for a, b in ops:
            mina = min(a, mina)
            minb = min(b, minb)

        return mina * minb
