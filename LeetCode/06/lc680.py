# lc680.py

# LeetCode 680. Valid Palindrome II `E`
# 1sk | 98% | 57'
# A~0g24

class Solution:
    def validPalindrome(self, s: str) -> bool:
        r = s[::-1]
        if r == s:
            return True

        l = len(s)
        for i in range(l):
            if s[i] != r[i]:
                break

        sub1 = s[i:l-i-1]
        sub2 = s[i+1:l-i]
        return sub1 == sub1[::-1] or sub2 == sub2[::-1]
