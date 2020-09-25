# LeetCode 993. Cousins in Binary Tree `E`
# 1sk | 92% | 38'
# A~0v25

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root:
            return False

        self.x, self.y = x, y
        self.xDepth, self.yDepth = None, None
        self.xParent, self.yParent = None, None
        self.dfs(root, 0, None)
        return self.xDepth == self.yDepth and self.xParent != self.yParent

    def dfs(self, node, depth, parent):
        if not node:
            return

        if node.val == self.x:
            self.xDepth = depth + 1
            self.xParent = parent
        elif node.val == self.y:
            self.yDepth = depth + 1
            self.yParent = parent

        self.dfs(node.left, depth+1, node)
        self.dfs(node.right, depth+1, node)
