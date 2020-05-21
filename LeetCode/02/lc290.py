# lc290.py

# LeetCode 290. Word Pattern `E`
# acc | 98% | 60'
# A~0e21


class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        lst = str.split()
        if len(pattern) != len(lst) or len(set(pattern)) != len(set(lst)):
            return False

        dic = {}
        for i, c in enumerate(pattern):
            if c in dic:
                if dic[c] != lst[i]:
                    return False
            else:
                dic[c] = lst[i]

        return True
