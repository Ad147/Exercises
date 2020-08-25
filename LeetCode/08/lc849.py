# LeetCode 849. Maximize Distance to Closest Person `E`
# acc | 98% | 15'
# A~0h25

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        dists = []
        prv = 0
        for i, s in enumerate(seats):
            if s:
                dists.append(i-prv)
                prv = i

        return max(seats.index(1), seats[::-1].index(1), max(dists) // 2)
