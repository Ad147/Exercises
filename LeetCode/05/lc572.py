# lc572.py

# LeetCode 572. Subtree of Another Tree `E`
# acc | 93% | 33'
# A~0g01

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        ss = self.traverse(s)
        st = self.traverse(t)
        return st in ss

    def traverse(self, t):
        if not t:
            return None

        return f"# {self.traverse(t.left)} {t.val} {self.traverse(t.right)}"


# recursive solution
# class Solution:
#     def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
#         if not s:
#             return False

#         if self.isSameTree(s, t):
#             return True

#         return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

#     def isSameTree(self, s: TreeNode, t: TreeNode) -> bool:
#         if not s and not t:
#             return True
#         elif not s or not t:
#             return False
#         elif s.val != t.val:
#             return False

#         return self.isSameTree(s.left, t.left) and self.isSameTree(s.right, t.right)
