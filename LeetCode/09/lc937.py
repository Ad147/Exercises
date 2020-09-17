# LeetCode 937. Reorder Data in Log Files `E`
# acc | 98% | 14'
# A~0v17

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        return sorted([l for l in logs if l[-1].isalpha()], key=lambda s: s[s.index(" "):]+s) + [l for l in logs if l[-1].isdigit()]
