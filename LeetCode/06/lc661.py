# lc661.py

# LeetCode 661. Image Smoother `E`
# acc | 54% | 60'
# A~0g19

class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        row, col = len(M), len(M[0])
        res = [[0 for j in range(col)] for i in range(row)]
        for i in range(row):
            for j in range(col):
                a = [M[x][y] for x in range(max(0, i-1), min(row, i+2))
                     for y in range(max(0, j-1), min(col, j+2))]
                res[i][j] = sum(a) // len(a)

        return res
