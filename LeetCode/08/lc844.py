# LeetCode 844. Backspace String Compare `E`
# acc | 87% | 67'
# A~0h22

class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def build(str):
            res = []
            skip = 0
            for c in reversed(str):
                if c == "#":
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    res.append(c)
            return res

        return build(S) == build(T)
