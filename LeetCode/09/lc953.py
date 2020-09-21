# LeetCode 953. Verifying an Alien Dictionary `E`
# 1sk | 97% | 22'
# A~0v21

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        dic = {c: i for i, c in enumerate(order)}

        def cmp(s1, s2):
            for i in range(min(len(s1), len(s2))):
                if s1[i] != s2[i]:
                    return dic[s1[i]] <= dic[s2[i]]
            return len(s1) <= len(s2)

        return all(cmp(words[i], words[i+1]) for i in range(len(words)-1))
