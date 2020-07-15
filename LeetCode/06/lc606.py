# lc606.py

# LeetCode 606. Construct String from Binary Tree `E`
# 1sk | 97% | 18'
# A~0g11

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ""

        res = str(t.val)
        if t.left or t.right:
            res += "(" + self.tree2str(t.left) + ")"
        if t.right:
            res += "(" + self.tree2str(t.right) + ")"

        return res
