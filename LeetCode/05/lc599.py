# lc599.py

# LeetCode 599. Minimum Index Sum of Two Lists `E`
# acc | 99% | 29'
# A~0g09

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        map = {s: i for i, s in enumerate(list1)}
        res = []
        minidx = 65536
        for i, s in enumerate(list2):
            if s in map:
                idx = i + map[s]
                if idx < minidx:
                    res.clear()
                    res.append(s)
                    minidx = idx
                elif idx == minidx:
                    res.append(s)

        return res
