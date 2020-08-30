# LeetCode 859. Buddy Strings `E`
# 1sk | 98% | 13'
# A~0h30

class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        countA = Counter(A)
        countB = Counter(B)
        if countA != countB:
            return False
        if A == B:
            for k, v in countA.items():
                if v > 1:
                    return True
        difIdxs = []
        for i in range(len(A)):
            if A[i] != B[i]:
                difIdxs.append(i)
            if len(difIdxs) > 2:
                return False
        if len(difIdxs) != 2:
            return False
        return A[difIdxs[0]] == B[difIdxs[1]] and A[difIdxs[1]] == B[difIdxs[0]]
