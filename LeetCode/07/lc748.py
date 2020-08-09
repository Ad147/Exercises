# LeetCode 748. Shortest Completing Word `E`
# acc | 94% | 50'
# A~0h09

class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        lpcounter = Counter([c.lower() for c in licensePlate if c.isalpha()])
        words.sort(key=lambda w: len(w))
        for w in words:
            for k, v in lpcounter.items():
                if w.count(k) < v:
                    break
            else:
                return w
