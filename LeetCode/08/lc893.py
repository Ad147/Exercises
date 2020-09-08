# LeetCode 893. Groups of Special-Equivalent Strings `E`
# acc | 100% | 21'
# A~0v08

class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        return len({"".join(sorted(s[::2])) + "".join(sorted(s[1::2])) for s in A})
