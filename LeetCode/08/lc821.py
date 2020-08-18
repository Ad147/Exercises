# LeetCode 821. Shortest Distance to a Character `E`
# 1sk | 98% | 13'
# A~0h18

class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        cIdxs = [i for i, c in enumerate(S) if c == C]
        ans = []
        for i in range(cIdxs[0]):
            ans.append(cIdxs[0] - i)
        for i in range(len(cIdxs)-1):
            for j in range(cIdxs[i], cIdxs[i+1]):
                ans.append(min(j - cIdxs[i], cIdxs[i+1] - j))
        for i in range(cIdxs[-1], len(S)):
            ans.append(i - cIdxs[-1])

        return ans
