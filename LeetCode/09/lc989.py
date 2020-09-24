# LeetCode 989. Add to Array-Form of Integer `E`
# 1sk | 49% | 4'
# A~0v24

class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        num = int("".join(str(d) for d in A))
        return [int(s) for s in str(num+K)]
