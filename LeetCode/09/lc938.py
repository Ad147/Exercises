# LeetCode 938. Range Sum of BST `E`
# 1sk | 88% | 11'
# A~0v18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        self.sum = 0
        self.traverse(root, L, R)
        return self.sum

    def traverse(self, node, L, R):
        if not node:
            return
        if L <= node.val <= R:
            self.sum += node.val
        if node.val > L:
            self.traverse(node.left, L, R)
        if node.val < R:
            self.traverse(node.right, L, R)
