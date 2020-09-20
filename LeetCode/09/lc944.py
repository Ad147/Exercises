# LeetCode 944. Delete Columns to Make Sorted `E`
# acc | 90% | 16'
# A~0v20

class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        return sum(list(col) != sorted(col) for col in zip(*A))
