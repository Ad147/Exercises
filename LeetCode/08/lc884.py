# LeetCode 884. Uncommon Words from Two Sentences `E`
# 1sk | 84% | 10'
# A~0v05

class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        wordsA, wordsB = A.split(), B.split()
        setA, setB = set(wordsA), set(wordsB)
        countA, countB = Counter(wordsA), Counter(wordsB)
        return [w for w in setA-setB if countA[w] == 1] + [w for w in setB-setA if countB[w] == 1]
