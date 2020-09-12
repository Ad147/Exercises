# LeetCode 914. X of a Kind in a Deck of Cards `E`
# acc | 90% | 43'
# A~0v12

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # def gcd(a, b):
        #     while b:
        #         a, b = b, a % b
        #     return a
        counts = Counter(deck).values()
        return reduce(math.gcd, counts) >= 2
