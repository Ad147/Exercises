# lc1033.py

# LeetCode 1033 Moving Stones Until Consecutive `E`
# A~0c08
# 1sk | 90%


class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        if a < 1 or a > 100 or b < 1 or b > 100 or c < 1 or c > 100:
            return [-1, -1]

        a, b, c = sorted([a, b, c])

        minMoves = -1
        if a + 1 == b and b + 1 == c:
            minMoves = 0
        elif a + 1 == b or b + 1 == c or a + 2 == b or b + 2 == c:
            minMoves = 1
        else:
            minMoves = 2

        return [minMoves, c - a - 2]

