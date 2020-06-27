# lc551.py

# LeetCode 551. Student Attendance Record I `E`
# acc | 91% | 13'
# A~0f27


class Solution:
    def checkRecord(self, s: str) -> bool:
        a = 0
        l = 0
        for c in s:
            if c == "L":
                l += 1
                if l > 2:
                    return False
            else:
                l = 0
                if c == "A":
                    a += 1
                    if a > 1:
                        return False
        return True
