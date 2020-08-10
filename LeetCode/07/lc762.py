# LeetCode 762. Prime Number of Set Bits in Binary Representation `E`
# acc | 95% | 18'
# A~0h10

class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        PRIME = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(bin(i).count("1") in PRIME for i in range(L, R+1))
