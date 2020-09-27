# LeetCode 999. Available Captures for Rook `E`
# 1sk | 96% | 22'
# A~0v27

class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        x, y = [(i, j) for i in range(8)
                for j in range(8) if board[i][j] == "R"][0]
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            i, j = x+dx, y+dy
            while 0 <= i < 8 and 0 <= j < 8:
                if board[i][j] == "p":
                    ans += 1
                    break
                elif board[i][j] == "B":
                    break
                i += dx
                j += dy
        return ans
