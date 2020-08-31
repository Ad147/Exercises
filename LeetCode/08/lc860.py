# LeetCode 860. Lemonade Change `E`
# 1sk | 98% | 10'
# A~0h31

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = 0
        for b in bills:
            if b == 5:
                five += 1
            elif b == 10:
                if not five:
                    return False
                else:
                    five -= 1
                    ten += 1
            else:
                if ten and five:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False

        return True
