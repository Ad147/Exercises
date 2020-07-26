# lc690.py

# LeetCode 690. Employee Importance `E`
# 1sk | 98% | 15'
# A~0g26

"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        res = 0
        d = {e.id: e for e in employees}
        q = [id]
        while q:
            a = q.pop()
            res += d[a].importance
            for i in d[a].subordinates:
                q.append(i)

        return res
