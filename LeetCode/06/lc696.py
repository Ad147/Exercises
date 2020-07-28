# lc696.py

# LeetCode 696. Count Binary Substrings `E`
# acc | 96% | 58'
# A~0g28

class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        s = s.replace("01", "0 1")
        s = s.replace("10", "1 0")
        s = [len(ss) for ss in s.split()]
        ans = 0
        for a, b in zip(s, s[1:]):
            ans += min(a, b)

        return ans
