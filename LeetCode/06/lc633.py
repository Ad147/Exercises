# lc633.py

# LeetCode 633. Sum of Square Numbers `E`
# acc | 96% | 31'
# A~0g14

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        '''
        based on Fermat's Theorem:
        > Any positive number nn is expressible as a sum of two squares if and only if the prime factorization of nn, every prime of the form (4k+3) occurs an even number of times.
        '''
        for i in range(2, ceil(sqrt(c))):
            cnt = 0
            if c % i == 0:
                while c % i == 0:
                    cnt += 1
                    c //= i

                if i % 4 == 3 and cnt % 2 != 0:
                    return False

        return c % 4 != 3
