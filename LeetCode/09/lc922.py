# LeetCode 922. Sort Array By Parity II `E`
# 1sk | 80% | 13'
# A~0v14

class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        evens = [a for a in A if a % 2 == 0]
        odds = [a for a in A if a % 2 != 0]
        ans = []
        for i in range(len(A)//2):
            ans.append(evens[i])
            ans.append(odds[i])
        return ans
