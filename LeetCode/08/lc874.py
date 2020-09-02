# LeetCode 874. Walking Robot Simulation `E`
# acc | 94% | 54'
# A~0v02

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacles = set(map(tuple, obstacles))
        dx = (0, 1, 0, -1)
        dy = (1, 0, -1, 0)
        ans = 0
        x = y = di = 0
        for cmd in commands:
            if cmd == -1:
                di = (di+1) % 4
            elif cmd == -2:
                di = (di-1) % 4
            else:
                for k in range(1, cmd+1):
                    if (x+dx[di]*k, y+dy[di]*k) in obstacles:
                        x += dx[di]*(k-1)
                        y += dy[di]*(k-1)
                        break
                else:
                    x += dx[di]*cmd
                    y += dy[di]*cmd
            ans = max(x**2 + y**2, ans)
        return ans
