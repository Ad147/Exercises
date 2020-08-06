# LeetCode 720. Longest Word in Dictionary `E`
# acc | 95% | 56'
# A~0h06

class Solution(object):
    def longestWord(self, words):
        ans = ""
        wordset = set(words)
        for w in words:
            if len(w) > len(ans) or len(w) == len(ans) and w < ans:
                if all(w[:k] in wordset for k in range(1, len(w))):
                    ans = w

        return ans
