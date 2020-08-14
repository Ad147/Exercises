# LeetCode 796. Rotate String `E`
# acc | 99% | 20'
# A~0h14

class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        return len(A) == len(B) and B in A+A
