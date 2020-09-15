# LeetCode 925. Long Pressed Name `E`
# acc | 88% | 27'
# A~0v15

class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i = j = 0
        cnti = cntj = 1
        while i < len(name)-1:
            while i < len(name)-1 and name[i] == name[i+1]:
                i += 1
                cnti += 1
            while j < len(typed)-1 and typed[j] == typed[j+1]:
                j += 1
                cntj += 1
            if name[i] != typed[j] or cnti > cntj:
                return False
            i += 1
            j += 1
            cnti = cntj = 1

        return (i == len(name) and j == len(typed)) or (i < len(name) and j < len(typed) and all(c == name[i] for c in list(typed[j:])))
