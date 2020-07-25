# lc686.py

# LeetCode 686. Repeated String Match `E`
# acc | 96% | 37'
# A~0g25

class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        if set(A) < set(B):
            return -1

        n = ceil(len(B)/len(A))
        for k in (n, n+1):
            if B in A*k:
                return k

        return -1
