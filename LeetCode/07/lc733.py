# LeetCode 733. Flood Fill `E`
# acc | 97% | 45'
# A~0h07

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        lr, lc = len(image), len(image[0])
        oldColor = image[sr][sc]
        if oldColor == newColor:
            return image

        def dfs(r, c):
            if image[r][c] == oldColor:
                image[r][c] = newColor
                if r > 0:
                    dfs(r-1, c)
                if r < lr-1:
                    dfs(r+1, c)
                if c > 0:
                    dfs(r, c-1)
                if c < lc-1:
                    dfs(r, c+1)

        dfs(sr, sc)
        return image
