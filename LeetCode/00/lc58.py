# lc58.py

# LeetCode 58. Length of Last Word `E`
# acc | 86% | 17'
# A~0d08


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0 or len(s.split()) == 0:
            return 0

        return len(s.split()[-1])
