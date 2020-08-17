# LeetCode 819. Most Common Word `E`
# acc | 73% | 58'
# A~0h17

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = "".join(c.lower() if c.isalnum()
                            else " " for c in paragraph)
        count = Counter(paragraph.split())
        banned = set(banned)
        for w in sorted(count.items(), key=lambda w: (w[1], w[0]), reverse=True):
            if w[0] not in banned:
                return w[0]
