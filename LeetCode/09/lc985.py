# LeetCode 985. Sum of Even Numbers After Queries `E`
# 1sk | 88% | 23'
# A~0v23

class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        evenSum = sum(even for even in A if even % 2 == 0)
        for v, i in queries:
            aEven, vEven = A[i] % 2 == 0, v % 2 == 0
            if aEven:
                if vEven:
                    evenSum += v
                else:
                    evenSum -= A[i]
            elif not vEven:
                evenSum += A[i] + v
            A[i] += v
            ans.append(evenSum)
        return ans
