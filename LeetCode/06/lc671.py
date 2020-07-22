# lc671.py

# LeetCode 671. Second Minimum Node In a Binary Tree `E`
# acc | 99% | 42'
# A~0g22

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root or not root.left:
            return -1

        l2min = self.findSecondMinimumValue(root.left) \
            if root.left.val == root.val else root.left.val
        r2min = self.findSecondMinimumValue(root.right) \
            if root.right.val == root.val else root.right.val

        return max(l2min, r2min) if l2min == -1 or r2min == -1 else min(l2min, r2min)
