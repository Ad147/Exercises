# LeetCode 824. Goat Latin `E`
# acc | 99% | 14'
# A~0h19

class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowels = ("a", "e", "i", "o", "u", "A", "E", "I", "O", "U")
        S = [w+"ma"+"a"*(i+1) if w[0] in vowels else w[1:] +
             w[0]+"ma"+"a"*(i+1) for i, w in enumerate(S.split())]
        return " ".join(S)
