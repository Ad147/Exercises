# LeetCode 997. Find the Town Judge `E`
# acc | 100% | 13'
# A~0v26

class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N == 1:
            return 1
        trustedCount = Counter(t[1] for t in trust)
        judge = [t[0] for t in trustedCount.items() if t[1] == N-1]
        return -1 if len(judge) == 0 or judge[0] in (t[0] for t in trust) else judge[0]
