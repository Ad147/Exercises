# LeetCode 897. Increasing Order Search Tree `E`
# 1sk | 89% | 19'
# A~0v10

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        ans = self.tree = TreeNode(None)
        self.inorder(root)
        return ans.right

    def inorder(self, node):
        if not node:
            return
        self.inorder(node.left)
        node.left = None
        self.tree.right = node
        self.tree = node
        self.inorder(node.right)
