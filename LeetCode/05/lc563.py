# lc563.py

# LeetCode 563. Binary Tree Tilt `E`
# 1sk | 85% | 26'
# A~0f29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.treeTilt = 0

    def findTilt(self, root: TreeNode) -> int:
        self.subtreeSum(root)

        return self.treeTilt

    def subtreeSum(self, node: TreeNode) -> int:
        if not node:
            return 0

        lsum = self.subtreeSum(node.left)
        rsum = self.subtreeSum(node.right)
        self.treeTilt += abs(lsum - rsum)

        return lsum + rsum + node.val
