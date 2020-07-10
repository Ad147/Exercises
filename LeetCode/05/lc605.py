# lc605.py

# LeetCode 605. Can Place Flowers `E`
# acc | 82% | 24'
# A~0g10

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        combo = 1
        for i in flowerbed:
            if n <= 0:
                break
            if i == 0:
                combo += 1
            else:
                n -= (combo - 1) // 2
                combo = 0
        n -= combo // 2

        return n <= 0
