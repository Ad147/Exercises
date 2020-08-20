# LeetCode 830. Positions of Large Groups `E`
# acc | 97% | 12'
# A~0h20

class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        ans = []
        prev, sta = " ", 0
        for i, c in enumerate(S):
            if c != prev:
                if i - sta >= 3:
                    ans.append((sta, i-1))
                sta = i
                prev = c
        if len(S) - sta >= 3:
            ans.append((sta, len(S)-1))

        return ans
